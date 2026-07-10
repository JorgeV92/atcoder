#include <iostream>
#include <vector>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int A, D; std::cin >> A >> D;
  std::cout << (A <= D ? "Yes" : "No") << '\n';
  return 0;
}
