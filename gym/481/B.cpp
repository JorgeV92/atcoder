#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int N, K; std::cin >> N >> K;
    std::vector<int> A(N);
    for (int &a : A) std::cin >> a;
    int cnt = 0;
    for (int a : A) cnt += a == K;
    for (int i = 0; i + 1 < N; i++) {
        cnt += (A[i] < K && A[i + 1] > K) || (A[i] > K && A[i + 1] < K);
    }
    std::cout << cnt << '\n';
    return 0;
}
