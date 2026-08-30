#include <iostream>
#include <vector>
#include <numeric>
template<class T> using V = std::vector<T>;
#define vi V<int>
struct DSU {
  vi e; void init(int N) { e = vi(N,-1); }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool unite(int x, int y) { 
    x = get(x), y= get(y); if (x == y) return false;
    if (e[x] > e[y]) std::swap(x, y);
    e[x] += e[y], e[y] = x; return true;
  }
};
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  struct edge {
    int u, v, w;
  };
  int T; std::cin >> T;
  while (T--) { 
    int N, M, K; std::cin >> N >> M >> K;
    std::vector<edge> ed;
    for (int i = 0; i < M; i++) {
      int u, v, w; std::cin >> u >> v >> w;
      u--; v--;
      ed.push_back(edge{u, v, w});
    }
    DSU dsu1;
    dsu1.init(N);
    for (const auto& e : ed) {
      if (e.w == 0) dsu1.unite(e.u, e.v);
    }
    DSU dsu2 = dsu1;
    std::vector<int> O;
    for (int i = 0; i < M; ++i) {
      const auto& [u, v, w] = ed[i];
      if (w == 1 && dsu2.unite(u, v)) O.push_back(i);
    }
    if ((int)O.size() > K) {
      std::cout << -1 << '\n';
      continue;
    }
    DSU tree;
    tree.init(N);
    std::vector<int> ans;
    std::vector<bool> used(M);
    int ones = 0;
    for (int i : O) {
      tree.unite(ed[i].u, ed[i].v);
      used[i] = 1;
      ans.push_back(i);
      ++ones;
    }

    for (int i = 0; i < M && ones < K; ++i) {
      if (used[i] || ed[i].w == 0) continue;
      if (tree.unite(ed[i].u, ed[i].v)) {
        used[i] = true;
        ans.push_back(i);
        ++ones;
      }
    }
    if (ones < K) {
      std::cout << -1 << '\n';
      continue;
    }
    
    for (int i = 0; i < M; ++i) {
      if (ed[i].w == 0 && tree.unite(ed[i].u, ed[i].v)) {
        used[i] = 1;
        ans.push_back(i);
      }
    }

    if ((int)ans.size() != N-1) {
      std::cout << -1 << '\n';
      continue;
    }
    for (int x : ans) {
      std::cout << x+1 << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
