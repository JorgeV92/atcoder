#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int64_t dp[3005][3005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        dp[i][i] = a[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len -1 < n; l++) {
            int r = l + len - 1;
            dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
        }
    }
    cout << dp[0][n-1] << '\n';
    return 0;
}