#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxnm = 102;
int C[maxnm];
int S[maxnm];
int MX[maxnm];
int N, M;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  cin  >> N >> M;
  memset(MX, -1, sizeof(MX));
  for (int i = 1; i <= N; i++) {
    cin >> C[i] >> S[i];
  }
  for (int i = 1; i <= N; ++i) {
    MX[C[i]] = max(MX[C[i]], S[i]);
  }
  for (int i = 1; i <= M; ++i) cout << MX[i] << ' ';
  cout << '\n';
  return 0;
}
