#include <iostream>
#include <vector>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int T; std::cin >> T;
  while (T--) {
    int n; std::cin >> n;
    std::vector<int> a(n); for (int  i = 0; i < n; ++i) std::cin >> a[i];
    bool losing = true;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == 1) {
        cnt++;
      } else {
        if (cnt > 0 && cnt != 2) {
          losing = false;
        }
        cnt = 0;
      }
    }

    if (cnt > 0 && cnt != 2) losing = false;
    std::cout << (losing ? "Bob" : "Alice") << '\n';
  }
  return 0;
}
