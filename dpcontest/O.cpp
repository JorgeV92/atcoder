#include <iostream>
#include <vector>
using namespace std;

#define rep(i,a,b) for (int i = (a); i < (b); i++) 
#define bit(n,k) ((n>>k) & 1) // (S & (1 << k))

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> a(N, vector<int>(N));
    rep(i,0,N)
        rep(j,0,N)
            cin >> a[i][j];
    vector<int> dp(1 << N);
    dp[0]= 1;
    rep(S,1,1<<N) {
        int i = __builtin_popcount(S); 
        rep(j,0,N) {
            if (bit(S,j) == 1 && a[i-1][j] == 1) {
                dp[S] += dp[S ^ (1<<j)];
                if (dp[S] >= MOD) dp[S] -= MOD;
            }
        }
    }
    cout << dp[(1<<N) - 1] << '\n';
    return 0;
}