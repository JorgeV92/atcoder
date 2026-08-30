#include <iostream>
#include <vector>
#include <cstdint>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int64_t B, C; std::cin >> B >> C;

    auto getInterval = [&](int64_t cost) -> std::pair<int64_t, int64_t> {
        if (cost == 0) return {B, B};
        int64_t n = cost / 2;
        if (cost % 2 == 1) {
            return {-B -n, -B + n};
        } else { 
            return {B - n, B + n - 1};
        }
    };

    auto [l1, r1] = getInterval(C);
    auto [l2, r2] = getInterval(C-1);

    int64_t sz1 = r1 - l1 + 1;
    int64_t sz2 = r2 - l2 + 1;
    int64_t u = std::max(0LL, std::min(r1,r2) - std::max(l1,l2) + 1LL);
    int64_t ans = sz1 + sz2 - u;
    std::cout << ans << '\n';
    return 0;
}