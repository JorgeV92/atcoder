#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  std::vector<std::vector<int>> g(n);
  std::vector<int> ind(n);
  for (int i = 0; i < m; ++i) {
    int u, v; std::cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    ind[v]++;
  }
  std::vector<int> left(n), right(n);
  for (int v = 0; v < n; ++v) std::cin >> left[v] >> right[v];
  std::vector<int> ind2 = ind;
  std::queue<int> q;
  for (int v = 0; v < n; ++v) {
    if (ind2[v] == 0) q.push(v);
  }
  std::vector<int> topo; topo.reserve(n);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    topo.push_back(u);
    for (int v : g[u]) {
      if (!--ind2[v]) q.push(v);
    }
  }
  if ((int)topo.size() != n) {
    std::cout << "No\n";
    return 0;
  }
  for (int i = n-1; i >= 0; --i) {
    int u = topo[i];
    for (int v : g[u]) {
      right[u] = std::min(right[u], right[v] - 1);
    }
  }
  for (int v = 0; v < n; ++v) {
    if (left[v] > right[v]) {
      std::cout << "No\n";
      return 0;
    }
  }
  using pi = std::pair<int,int>;
  std::priority_queue<pi, std::vector<pi>, std::greater<pi>> wait, ready;
  ind2 = ind;
  for (int v = 0; v < n; ++v) {
    if (ind2[v] == 0) wait.push({left[v], v});
  }
  std::vector<int> ans(n);
  for (int i = 1; i <= n; ++i) {
    while (!wait.empty() && wait.top().first <= i) {
      int v = wait.top().second;
      wait.pop();
      ready.push({right[v], v});
    } 
    if (ready.empty()) {
      std::cout << "No\n";
      return 0;
    }
    auto [last, cur] = ready.top();
    ready.pop();
    if (last < i) {
      std::cout << "No\n";
      return 0;
    }
    ans[cur] = i;
    for (int u : g[cur]) {
      if(!--ind2[u]) wait.push({left[u], u});
    }
  }
  std::cout << "Yes\n";
  for (int v = 0; v < n; ++v) {
    std::cout << ans[v] << " \n"[v+1==n];
  }
  return 0;
}
