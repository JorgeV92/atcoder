#include <iostream>
#include <vector>
using namespace std;
vector<int> g[200002];
int n, m;
bool vis[200002];
int par[200002];
int color[200002];
int cycle_start = -1;
int cycle_end = -1;

bool dfs(int v, int f) {
    vis[v] = true;
  for (int u : g[v]) {
    if (u == f) continue;
    if (vis[u]) {
      if (color[v] == color[u]) {
        cycle_start = u;
        cycle_end = v;
        return true;
      }
      continue;
    }
    par[u] = v;
    color[u] = color[v] ^ 1;
    if (dfs(u ,v)) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int t; cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      g[i].clear();
      vis[i] = false;
      par[i] = -1;
      color[i] = 0;
    }
    cycle_start = -1, cycle_start = -1;
    for (int i = 0; i < m; i++) {
      int a, b; cin >> a >> b;
      a--; b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    dfs(0,-1);
    if (cycle_start == -1) {
      cout << -1 << '\n';
      continue;
    }
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = par[v]) {
      cycle.push_back(v);
    }
    cout << cycle.size() << '\n';
    for (int v : cycle) cout << v + 1 << ' ';
    cout << '\n';
  }
  return 0;
}
