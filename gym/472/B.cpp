#include <climits>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int N; cin >> N;
  vector<int> L(N); for (int& l : L) cin >> l;
  vector<int> pref(N+1), suf(N+1); 
  for (int i = 0; i < N; i++) 
      pref[i+1] = pref[i] + L[i];
  for (int i = N-1; i >= 0; i--)
      suf[i] = suf[i+1] + L[i];
  int mn = INT_MAX;
  for (int i = 0; i < N-1; i++) {
    mn = min(mn, abs(pref[i+1] - suf[i+1]));
  }
  cout << mn << '\n';
  return 0;
}
