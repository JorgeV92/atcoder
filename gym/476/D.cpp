#include <iostream>
#include <vector>
#include <algorithm>
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int N, M; i64 K;
    std::cin >> N >> M >> K;
    i64 X, Y; std::cin >> X >> Y;
    std::vector<i64> A(N), B(M);
    for (auto& x : A) std::cin >> x;
    for (auto& x : B) std::cin >> x;
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    std::vector<i64> prefA(N+1);
    for (int i = 0; i < N; ++i) prefA[i+1] = prefA[i] + A[i];
    std::vector<i64> prefB(M+1), prefBB(M+1);
    for (int i = 0; i < M; i++) {
        prefB[i+1] = prefB[i] + B[i];
        i64 b = (B[i] + K - 1) / K;
        prefBB[i+1] = prefBB[i] + b;
    }
    i64 total = X + Y * K;
    int ans = 0;
    for (int d= 0; d <= M; ++d) {
        if (prefBB[d] > Y) break;
        if (prefB[d] > total) break;
        i64 r = total - prefB[d];
        int a = std::upper_bound(prefA.begin(), prefA.end(), r) - prefA.begin()-1;
        ans = std::max(ans, d + a);
    }
    std::cout << ans << '\n';
    return 0;
}