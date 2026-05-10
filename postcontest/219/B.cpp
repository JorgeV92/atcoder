#include <iostream>
#include <vector>
#include <algorithm>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

int main() {
    auto jorgee = [&]() -> void {
        int T; cin >> T;
        while (T--) {
            int n; cin >> n;
            vector<int> p(n); for (int i = 0; i < n; i++) cin >> p[i];
            int f = 0;
            for (int i = 1; i <= n; i++) {
                if (p[i-1] == i) f++;
                else break;
            }
            mint ans = 0;
            for (int i = 1; i <= f; i++) {
                ans += max(1, n-i);
            }
            cout << ans.val() << '\n';
        }
    }; jorgee();
    return 0;   
}