#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vector<pair<int64_t, int64_t>> a;
  for (int i = 0; i < n; ++i) {
    int64_t h, l; cin >> h >> l;
    while (!a.empty() && a.back().first <= h) a.pop_back();
    a.emplace_back(h,l);
  }
  int q; cin >> q;
  while (q--) {
    int t; cin >> t;
    auto it = upper_bound(a.begin(), a.end(), t, [&](int64_t x, auto& y) { return x < y.second; });
    cout << it->first << '\n';
  }
  
}
