#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int N; cin >> N;
  int cnt = 0;
  vector<int> a(N); for (int i = 0; i < N; ++i) cin >> a[i];
  for (int i = 0; i < N; ++i) { if (a[i] < 0) cnt++; }
  cout << (cnt == (int)a.size() ? "Yes" : "No") << '\n';
  return 0;
}
