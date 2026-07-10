#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<char, int> mp{{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}};
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int N; char X; cin >> N >> X;
  int id = mp[X];
  vector<string> S(N); for (int i = 0; i < N; ++i) cin >> S[i];
  for (int i = 0; i < N; ++i) {
    if (S[i][id] == 'o') {
      cout << "Yes\n";
      return 0;
    }
  } 
  cout << "No\n";
  return 0;
}
