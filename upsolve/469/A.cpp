#include <iostream>
#include <vector>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int N, K; std::cin >> N >> K;
  std::cout << N - K + 1 << '\n';
  return 0;
}
