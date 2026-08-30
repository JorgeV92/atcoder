#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int N, K; std::cin >> N >> K;
  std::string S; std::cin >> S;
  std::vector<int> pos;
  for (int i =0 ; i < N; ++i) {
    if (S[i] == 'o') pos.push_back(i+1);
  }
  std::vector<double> pref(N+1);
  auto possible = [&](double p) -> bool {
    pref[0] = 0.0;
    int wins = 0;
    int added = -1;
    double mn = std::numeric_limits<double>::infinity();
    for (int r = 1; r <= N; ++r) {
      if (S[r-1] == 'o') {
        pref[r] = pref[r-1] + (1.0 - p);
        ++wins;
      } else {
        pref[r] = pref[r-1] - p;
      }
      if (wins < K) continue;
      int tmax = pos[wins-K] - 1;
      while (added < tmax) {
        ++added;
        mn = std::min(mn, pref[added]);
      }
      if (pref[r] >= mn - 1e-12) return true;
    }
    return false;
  };
  double low = 0.0;
  double high = 1.0;
  for (int i = 0; i < 60; ++i) {
    double m = (low + high) / 2.0;
    if (possible(m)) {
      low = m;
    } else {
      high = m;
    }
  }
  std::cout << std::fixed << std::setprecision(15) << low << '\n';
  return 0;
}
