#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int N, M; cin >> N >> M;
  ll K; cin >> K;
  vector<ll> A(N); for (int i= 0; i < N; ++i) cin >> A[i];
  ll sum  =  0;
  for (int i = 0; i < N; ++i) {
    if (i >= M) {
      sum -= A[i-M];
    }
    if (sum + A[i] <= K) {
      sum += A[i];
      cout << "Yes\n";
    } else {
      A[i] = 0;
      cout << "No\n";
    }
  }
  return 0;
}
