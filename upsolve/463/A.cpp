#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int x, y; cin >> x >> y;
  if (9 * x == 16 * y) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}
