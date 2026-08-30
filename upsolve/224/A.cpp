#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  while (T--) {
    ll K; cin >> K;
    auto check = [&](ll x) {
      string s = to_string(x);
      return s.find("00") != string::npos;
    };
    for (ll m = 1; m <= 100; m++) {
      ll n = K * m;
      if (check(n)) {
        cout << n << '\n';
        break;
      }
    }
  }
  return 0;
}
