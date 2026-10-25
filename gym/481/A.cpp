#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int A, B; std::cin >> A >> B;
    int x = A + B;
    int cnt = 0;
    while (x) {
        cnt++;
        x /= 10;
    }
    std::cout << cnt << '\n';
    return 0;
}