#include <algorithm>
#include <iostream>
#include <vector>
struct Point {
    long long x, y;
};
long long cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
bool upper(const Point &p) {
    return p.y > 0 || (p.y == 0 && p.x > 0);
}
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T; std::cin >> T;
    while (T--) {
        int N; std::cin >> N;
        std::vector<Point> p(N);
        for (auto &[x, y] : p) std::cin >> x >> y;
        std::sort(p.begin(), p.end(), [](const Point &a, const Point &b) {
            if (upper(a) != upper(b)) return upper(a) > upper(b);
            return cross(a, b) > 0;
        });
        p.resize(2 * N);
        for (int i = 0; i < N; i++) p[i + N] = p[i];
        int ans = 1, j = 0;
        for (int i = 0; i < N; i++) {
            j = std::max(j, i);
            while (j + 1 < i + N && cross(p[i], p[j + 1]) > 0) j++;
            ans = std::max(ans, j - i + 1);
        }
        std::cout << ans << '\n';
    }
    return 0;
}
