#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    vector<bool> dp(k+1, false);
    dp[0] = false;
    for (int i = 1; i <= k; i++) {
        for (int x : a) {
            if (x > i) break;
            if(!dp[i-x]) {
                dp[i] = true;
                break;
            }
        }
    }
    cout << (dp[k] ? "First" : "Second") << "\n";
    return 0;
}