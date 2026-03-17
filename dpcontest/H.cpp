#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <string_view>
#include <map>
#include <set>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define OUT(x) cout << x << '\n'
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++) 
#define FORE(i,a,b) for(int i = (a); i <= (b); i++)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

using ll = long long;
using pii = pair<int,int>;

const int MOD = 1000000007;

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

vector<string> grid;
int dp[1105][1105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W;
    cin >> H >> W;
    grid.resize(H);
    FOR(i,0,H) {
        cin >> grid[i];
    }
    
    dp[0][0] = 1;
    FOR(r,0,H) {
        FOR(c,0,W) {
            if (r+1 < H && grid[r+1][c] == '.') add(dp[r+1][c], dp[r][c]);
            if (c+1 < W && grid[r][c+1] == '.') add(dp[r][c+1], dp[r][c]);
        }
    }
    
    cout << dp[H-1][W-1] << '\n';
    return 0;
}