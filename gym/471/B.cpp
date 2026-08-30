#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <unordered_map>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    unordered_map<string, int> mp;
    for (int i = 0; i < N; ++i) {
        string s; cin >> s;
        ::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
            return ::tolower(c);
        });
        mp[s]++;
    }
    int mx = 0;
    for (const auto& [s, cnt] : mp) {
        mx = max(mx, cnt);
    }
    cout << mx << '\n';
    return 0;
}