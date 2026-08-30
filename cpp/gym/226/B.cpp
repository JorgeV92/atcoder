#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        vector<int64_t> A(M);
        int64_t total = 0;
        for (int i = 0; i < M; ++i) {
            cin >> A[i];
            total += A[i] * (1LL << i);
        }

        auto check = [&](int64_t X) -> bool {
            __int128_t need = 0;
            for (int i = M-1; i >= 0; --i) {
                need = need * 2 + A[i];
                __int128_t cap = (__int128_t)N * (X >> i);
                if (need > cap) return false;
            }
            return true;
        };

        int64_t lo = 0;
        int64_t hi = total;

        while (lo < hi) {
            int64_t m = lo + (hi - lo) / 2;
            if (check(m)) {
                hi = m;
            } else {
                lo = m+1;
            }
        }
        cout << hi << '\n';
    }
    return 0;
}