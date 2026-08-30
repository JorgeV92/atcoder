#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  auto digit_count = [&](int x) {
    int d = 0;
    do {
      ++d;
      x /= 10;
    } while (x > 0);
    return d;
  };
  int T; cin >> T;
  while (T--) {
    int N, K; cin >> N >> K;
    vector<ll> ways;
    ll coll = 0;
    ll comb = 1;
    for (int r= 0; r <= N && coll < K; ++r) {
      ll take = min<ll>(comb, K-coll);
      ways.push_back(take);
      coll += take;
      if (coll == K || r == N) break;
      __int128_t nxt = (__int128_t)comb * (N - r) / (r  +1);
      comb = (ll)min<__int128_t>(nxt, K);
    }
    if (coll < K) {
      cout << -1 << '\n';
      continue;
    }
    ll ans = 0;
    int subset_size = 0;
    for (int x = K; x >= 1; --x) {
      while (ways[subset_size] == 0) subset_size++;
      ans += 1LL * subset_size * digit_count(x);
      --ways[subset_size];
    }
    cout << ans << '\n';

  }
  return 0; 
}
