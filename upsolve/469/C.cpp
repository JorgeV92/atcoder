#include <iostream>
#include <vector>
#include <string>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n; std::string s; std::cin >> n >> s;
  std::vector<int> pos;
  for (int i = 0; i < n; ++i) { if (s[i] == 'x') pos.push_back(i+1); }
  for (int k = 1; k <= n; k++) {
    if (k <= (int)pos.size()) {
      std::cout << pos[k-1] << '\n'; 
    } else {
      std::cout << n << '\n';
    }
  }
  return 0;
}
