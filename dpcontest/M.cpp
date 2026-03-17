#include <iostream>
#include <vector>
#include <atcoder/modint>
using namespace std;

using mint = atcoder::modint1000000007;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) 
        cin >> a[i];
    vector<vector<mint>> dp(N+1, vector<mint>(K+1));
    dp[0][0] = 1;
    for (int i = 0 ;i < N; i++) {
        vector<mint> pref(K+2,0);
        for (int j = 0; j <= K; j++) {
            pref[j+1] = pref[j] + dp[i][j];
        }
        for (int j = 0; j <= K; j++) {
            int L = max(0, j - a[i]);
            dp[i+1][j] = pref[j+1] - pref[L];
        }
    }
    cout << dp[N][K].val() << '\n';
}