#include <iostream>
#include <vector>
#include <string>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n; 
  std::string s; 
  std::cin >> n >> s;
  int cnt = (n==1 && s[0] == 'x');
  for (int i = 0; i < n; i++) {
    if (i == 0 && s[i] == 'x' && s[i+1] == 'x') {
      cnt++;
    } else if (i == n-1 && s[i] == 'x' && s[i-1] == 'x') {
      cnt++;
    } else if (s[i] == 'x' && s[i-1] == 'x' && s[i+1] == 'x') 
      cnt++;
  }
  std::cout << cnt << '\n';
  return 0;
}
