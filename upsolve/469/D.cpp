#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int N, M; std::cin >> N >> M;
  std::vector<std::pair<int,int>> e(M);
  for (int i = 0; i < M; ++i) std::cin >> e[i].first >> e[i].second;
  std::vector<std::pair<int, int>> pp;
  auto check = [&](int u, int v) {
    if (u == v) return false;
    for (const auto& [a, b] : e) {
      bool in_u = (a == u || b == u);
      bool in_v = (a == v || b == v);
      if (!in_u && !in_v) return false;
    }
    return true;
  };
  auto add = [&](int u, int v) {
    if (u == v) return;
    if (u > v) std::swap(u,v);
    pp.emplace_back(u,v);
  };  
  auto process = [&](int u) {
    int few = -1;
    for (int i = 0; i < M; ++i) {
      auto [a, b] = e[i];
      if (a != u && b != u) {
        few = i;
        break;
      }
    }
    if (few == -1) {
      for (int v = 1; v <= N; ++v) {
        if (v != u) add(u, v);
      }
      return;
    }
    auto [a, b] = e[few];
    if (check(u, a)) {
      add(u, a);
    }
    if (check(u, b)) {
      add(u, b);
    }
  };
  process(e[0].first); process(e[0].second);
  std::sort(pp.begin(), pp.end());
  pp.erase(std::unique(pp.begin(), pp.end()), pp.end());
  std::cout << (int)pp.size() << '\n';
  return 0;
}
