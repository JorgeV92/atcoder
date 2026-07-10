#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <queue>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, D; cin >> N >> D;
    vector<pair<int,int>> p(N);
    for (int i = 0; i < N; i++)  {
        int x, y; cin >> x >> y;
        p[i] ={x, y};
    }
    vector<vector<bool>> adj(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        auto [x, y] = p[i];
     for (int j = 0; j < N; j++) {
        auto [x2, y2] = p[j];
        int d = (x-x2) * (x-x2) + (y - y2) * (y - y2);
        if (d <= D * D) adj[i][j] = true;
     }  
    }
    vector<bool> ans(N);
    ans[0] = true;
    queue<int> q{{0}};
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < N; ++i) {
            if (adj[v][i] && !ans[i]) {
                ans[i] = true;
                q.push(i);
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        if (ans[i]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}