#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <numeric>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int N, K, M; std::cin >> N >> K >> M;
  std::vector<std::vector<int64_t>> J(N);
  for (int i = 0; i < N; ++i) {
    int c, v; std::cin >> c >> v;
    c--;
    J[c].push_back(v);
  }
  std::vector<int64_t> top, tail;
  for (auto& r : J) {
    if (r.size() > 0) {
      std::sort(r.begin(), r.end(), std::greater<int64_t>());
      top.push_back(r[0]);
      tail.insert(tail.end(), r.begin()+1, r.end());
    }
  }
  
  std::sort(top.begin(), top.end(), std::greater<int64_t>());
  tail.insert(tail.end(), top.begin()+M, top.end());
  std::sort(tail.begin(), tail.end(), std::greater<int64_t>());
  std::cout << std::accumulate(top.begin(), top.begin()+M, 0LL) + std::accumulate(tail.begin(), tail.begin() + (K-M), 0LL) << '\n';

  return 0;
} 
