#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using i128 = __int128_t;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  while (T--) {
    ll N; cin >> N;
    ll k = sqrtl(N);
    while ((i128)k*k >= N) k--;
    while ((i128)(k+1) * (k+1) < N) ++k;
    ll ans{};
    if ((i128)N <= (i128)k *(k+1)) {
      ans = 2 * N - (2 * k + 1);
    } else {
      ans = 2 * N - 2 * (k+1);
    }
    cout << ans << '\n';
  }
  

  return 0;
}
