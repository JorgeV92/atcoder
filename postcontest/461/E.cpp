#include <array>
#include <iostream>
#include <istream>
#include <vector>
#include <array>
#include <cstdint>
#include <cstring>
const int maxq = 3e5+5;

template<class T> struct fenwick {
  T b[maxq];
  int n{};
  
  fenwick(int _n = 0) { memset(b, 0, sizeof(b)); n = _n; } 

  T sum(int r) {
    T res{};
    for ( ; r > 0; r -= r & (-r)) {
      res += b[r];
    } 
    return res;
  }

  void add(int idx, int delta) {
    idx++;
    for (; idx <= n; idx += idx & (-idx)) {
      b[idx] += delta;
    }
  }

  T sum(int l, int r) {
    return sum(r) - sum(l);
  }

  void setn(int _n) {n = _n;}
};

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int N, Q; std::cin >> N >> Q;
  std::array<fenwick<int>, 2> f{
    fenwick<int>(Q+1),
    fenwick<int>(Q+1)
  };
  int64_t b = 0;
  std::array<std::vector<int>, 2> last{
    std::vector<int>(N+1,-1),
    std::vector<int>(N+1,0)
  };
  
  for (int i = 1; i <= Q; ++i)  {
    int t, x; std::cin >> t >> x;
    t--;
    if (last[t][x] == -1) 
        b += N;
    else {
      auto kind = f[1-t].sum(last[t][x], i);
      b += (t == 0 ? kind : -kind);
      f[t].add(last[t][x], -1);
    }
    f[t].add(i, 1);
    last[t][x] = i;
    std::cout << b << '\n';
  }

  return 0;
}
