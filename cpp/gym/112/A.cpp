#include <iostream>
#include <vector>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int64_t L, R; std::cin >> L >> R;
        int64_t D = R - 2 * L;
        if (D < 0) {
            std::cout << 0 << '\n';
        } else {
            int64_t tmp = (D+1) * (D+2) / 2;
            std::cout << tmp << '\n';
        }
    }
    return 0;
}