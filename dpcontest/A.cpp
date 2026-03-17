#include <iostream>
#include <vector>

using namespace std;

#define OUT(x) cout << x << '\n';
const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{};
    cin >> n;
    vector<int> h(n+2);
    for (int i = 0; i < n;i ++) {
        cin >> h[i];
    }
    vector<int> dp(n+2, inf);
    dp[0] = 0;
    // for (int i = 0; i < n; i ++) {
    //     dp[i+1] = min(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
    //     dp[i+2] = min(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
    // }

    for (int i = 0; i < n; i++) {
        if (i > 0)
            dp[i] = min(dp[i], dp[i-1] + abs(h[i]- h[i-1]));
        if (i > 1) 
            dp[i] = min(dp[i], dp[i-2] +abs(h[i]- h[i-2]) );
    }

    OUT(dp[n-1]);

    return 0;
}