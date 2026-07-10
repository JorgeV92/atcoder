#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
using ll = long long;
const ll mod = 998244353;
ll dp[2][2][3][1024];
ll ndp[2][2][3][1024];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string N; cin >> N;
    // dp[tight][started][rem][mask]
    dp[1][0][0][0] = 1;
    for (char c : N) {
        memset(ndp, 0, sizeof(ndp));
        int lim = c - '0';
        for (int t = 0; t <= 1; ++t) {
            for (int s = 0; s <= 1; ++s) {
                for (int rem = 0; rem < 3; ++rem) {
                    for (int mask = 0; mask < 1024; ++mask) {
                        ll cur = dp[t][s][rem][mask];
                        if (cur == 0) continue;
                        int l = t ? lim : 9;
                        for (int d = 0; d <= l; ++d) {
                            int nt = t && (d == l);
                            if (!s && d ==0) {
                                ndp[nt][0][0][0] += cur;
                                ndp[nt][0][0][0] %= mod;
                            } else {
                                int ns = 1;
                                int nr = (rem * 10 + d) % 3;
                                int nm = mask | (1 << d);
                                ndp[nt][ns][nr][nm] += cur;
                                ndp[nt][ns][nr][nm] %= mod;
                            }
                        }
                    }
                }
            }
        }
        memcpy(dp, ndp, sizeof(dp));
    }
    ll ans = 0;
    for (int t= 0; t <= 1; ++t) {
        for (int rem = 0; rem < 3; ++rem) {
            for (int mask = 0; mask < 1024; ++mask) {
                ll cur = dp[t][1][rem][mask];
                if (cur == 0) continue;
                int cnt = 0;
                if (rem == 0) cnt++;
                if (mask & (1 << 3)) cnt++;
                if (__builtin_popcount(mask) == 3) cnt++;
                if (cnt == 1) {
                    ans += cur;
                    ans %= mod;
                }
            }   
        }
    }
    cout << ans << '\n';

    return 0;
}