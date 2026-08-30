#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int D = 6;
const int BASE = 10;
const int M = 1000000;
int pw[D+1];
int encode(string& s) {
    int idx = 0;
    for (int i = 0; i < D; ++i) 
        idx += (s[i] - '0') * pw[i];
    return idx;
}
int get_digit(int idx, int d) {
    return (idx/pw[d]) % 10;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    pw[0] = 1;
    for (int i = 1; i <= D; ++i)
        pw[i] = pw[i-1] * 10;
    int N; cin >> N;
    vector<ll> pref(M, 0);
    for (int i = 0; i < N; ++i) {
        string S;
        ll V;
        cin >> S >> V;
        pref[encode(S)] += V;
    }
    for (int d = 0; d < D; ++d) {
        for (int idx = 0; idx < M; idx++) {
            if (get_digit(idx, d) > 0) 
                pref[idx] += pref[idx-pw[d]];
        }
    }
    int Q; cin >> Q;
    while (Q--) {
        string x, y; cin >> x >> y;
        bool ok = true;
        for (int i = 0; i < D; ++i) {
            if (x[i] > y[i]) 
                ok = false;
        }
        if (!ok) {
            cout << 0 << '\n';
            continue;
        }
        ll ans = 0;
        for (int mask = 0; mask < (1 << D); ++mask) {
            int idx = 0;
            bool valid = true;
            for (int d = 0; d < D; ++d) {
                int digit;
                if (mask & (1 << d)) {
                    digit = (x[d] - '0') - 1;
                    if (digit < 0) {
                        valid = false;
                        break;
                    }
                } else {
                    digit = y[d] - '0';
                }
                idx += digit * pw[d];
            }
            if (!valid) continue;
            if (__builtin_popcount(mask)%2 == 0) {
                ans += pref[idx];
            } else {
                ans -= pref[idx];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}