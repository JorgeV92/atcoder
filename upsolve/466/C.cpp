#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int N; cin >> N;
  ll cnt =  0;
  auto ask = [&](int i, int j) -> bool {
    cout << "? " << i << ' ' << j << endl;
    string s; cin >> s;
    return s == "Yes";
  };
  int r = 1;
  for (int l = 1; l <= N; ++l) {
    r = max(r, l);
    while (r+1 <= N) {
      if (ask(l,r+1)) r++;
      else break;
    }
    cnt += r-l;
  }
  cout << "! " << cnt << endl;
  return 0;
}
