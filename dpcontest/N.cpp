#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

const int64_t inf = 1e18;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int N; 
    cin >> N;
    vector<int64_t> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<int64_t> pref(N+1);
    for (int i = 0; i < N; i++) {
        pref[i+1] = pref[i] + a[i];
    }
    auto range_sum = [&](int l, int r) -> int64_t {
        return pref[r+1]- pref[l];
    };
    vector<vector<int64_t>> dp(N, vector<int64_t>(N, inf));
    for (int i = 0; i < N; i++) dp[i][i] = 0;
    for (int len = 2; len <= N; len++) {
        for (int l = 0; l + len - 1 < N; l++) {
            int r = l + len -1;
            int64_t total = range_sum(l, r);
            for (int k = l; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r] + total);
            }
        }
    }
    cout << dp[0][N-1] << '\n';
}