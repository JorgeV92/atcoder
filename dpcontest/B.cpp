#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>

using namespace std;

#define OUT(x) cout << x << '\n';
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

const int inf = 1e9;
const int MAXN = 1e5+7;

int h[MAXN];
int dp[MAXN];

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    fill(dp, dp+n+4, inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            chmin(dp[i+j], dp[i] + abs(h[i]-h[i+j]));
        }   
    }
    OUT(dp[n-1]);
    return 0;
}