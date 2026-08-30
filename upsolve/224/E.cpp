#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int T; cin >> T;
  while(T--) {
    string s; cin >> s;
    stack<int> st;
    int ans = 0;
    for (char c : s) {
      if (c == 'A') st.push(1);
      else if (c == 'B') {
        while (!st.empty() && st.top() != 1) st.pop();
        if (st.empty()) ans++; 
        else {
          st.pop();
          st.push(2);
        }
      } else {
        while (!st.empty() && st.top() != 2) st.pop();
        if (st.empty()) ans++;
        else st.pop();
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
