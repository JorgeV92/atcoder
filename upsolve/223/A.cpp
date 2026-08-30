#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N;
        ll W; 
        cin >> N >> W;
        vector<ll> w(N), v(N);
        ll ans = 0;
        ll tmp =0;
        for (int i = N-1; i >= 0; --i) {
            if (W < w[i]) continue;
            {
                ll tmp2 = tmp;
                for (int j = 0; j < i; ++j) tmp2 += v[j];
                ans = max(ans, tmp2);
            }
            W -= w[i];
            tmp += v[i];
        }
        ans = max(ans, tmp);
        cout << ans << '\n';
    }
    return 0;
}