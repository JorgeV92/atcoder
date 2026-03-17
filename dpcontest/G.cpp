#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

#define OUT(x) cout << x << '\n';
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++) 
#define FORE(i,a,b) for(i = (a); i <= (b); i++)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

using ll = long long;

const int MAXN = 100005;

int dist[MAXN];
int in[MAXN];
int dp[MAXN];
vector<vector<int>> adj;

int dfs(int v) {
    if (dist[v] != -1) 
        return dist[v];
    int res = 0;
    for (auto u : adj[v]) {
        chmax(res, dfs(u) + 1);
    }
    return dist[v] = res;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    adj = vector<vector<int>>(N);
    fill(dist,dist+MAXN,-1);

    FOR(i,0,M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        in[b]++;
    }
    
    int out = 0;
    FOR(i,0,N) {
        chmax(out, dfs(i));
    } 

    OUT(out); // dfs

    
    queue<int> q;
    FOR(i,0,N) {
        if (!in[i]) 
            q.push(i);
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : adj[v]) {
            in[u]--;
            chmax(dp[u], dp[v] + 1);
            if (!in[u]) {
                q.push(u);
            }
        }
    }

    int out2 = 0;
    FOR(i,0,N) {
        chmax(out2, dp[i]);
    }

    OUT(out2); // kahns

    return 0;
}