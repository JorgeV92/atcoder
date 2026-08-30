#include <iostream>
#include <vector>
#include <cstdint>
#include <atcoder/modint>
using namespace std;
using Mint = atcoder::static_modint<998244353>;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> m(2*n+1);
    for (int i = 0; i < n; ++i) {
        int s, t; cin >> s >> t;
        m[s] = +1;
        m[t] = -1;
    }
    int on = 0;
    int c = 0;
    for (int t = 1; t <= 2*n; ++t) {
        if (m[t] == +1) {
            if (on == 0) c++;
            
            on++;
            if (on >= 3) {
                cout << 0 << '\n';
                return 0;
            }
        } else {
            on--;
        }
    }
    Mint ans = Mint(2).pow(c);
    cout << ans.val() << '\n';

    return 0;
}