#include <iostream>
#include <optional>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  while (T--) {
    int N, M; cin >> N >> M;
    vector<vector<int>> g(N);
    for (int i = 0; i < M; ++i) {
      int u, v; cin >> u >> v;
      u--; v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<int> A(N,-1);
    auto dfs = [&](auto&& self, int u, int d) -> void {
      A[u] = d;
      for (auto v : g[u]) {
        if (A[v] == -1)
          self(self, v, d+1);
      }
    }; dfs(dfs, 0, 0);
    for (int i = 0; i < N; ++i) {
      cout << A[i] << " \n"[i+1==N];
    }
  }
  return 0;
}
