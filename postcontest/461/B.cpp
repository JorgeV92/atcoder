#include <iostream>
#include <vector>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int N; std::cin >> N;
  std::vector<int> A(N), B(N); 
  for (int i = 0; i < N; ++i) {
    int x; std::cin >> x;
    x--;
    A[i] = x;
  }
  for (int i = 0; i < N; ++i) {
    int x; std::cin >> x;
    x--;
    B[i] = x;
  }

  for (int i = 0; i < N; ++i) {
    if (A[B[i]] != i) {
      std::cout << "No\n";
      return 0;
    }
  }
  std::cout << "Yes\n";

  return 0;
}
