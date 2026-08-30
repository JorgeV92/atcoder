#include <iostream>
#include <vector>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> f{0,2,4,1,3};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x; std::cin >> x;
      std::cout << f[x] << ' ';
    }
    std::cout << '\n';
  }
  
  return 0;
}
