#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int64_t n, k; cin >> n >> k;
        int64_t res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int64_t x; cin >> x;
                if ((i+j) % 2 == 1) {
                    res ^= (x % (k+1));
                }
            }
        }
        cout << (res != 0 ? "Alice" : "Bob" ) << '\n';
    }
    return 0;
}