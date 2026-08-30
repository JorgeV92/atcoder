#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, K; cin >> N >> K;
    vector<string> S(N);

    for (auto&s  : S) {
        cin >> s;
    }

    sort(S.begin(), S.end(), [&](auto x, auto y) {
        if (x.size() != y.size()) {
            return x.size() > y.size();
        }
        return x > y;
    });

    auto build = [&](vector<string>& v) -> string {
        sort(v.begin(), v.end(), [&](auto a, auto b) {
            return a + b > b + a;
        });
        string ans{};
        for (const auto& s : v) {
            ans += s;
        }
        int i = 0;
        while (i < (int)ans.size() && ans[i] == '0') i++;
        if (i == (int)ans.size()) return "0";
        return ans.substr(i);
    };

     vector<string> c1; 
     for (int i = 0; i < K; i++) {
        c1.push_back(S[i]);
     }

     auto ans1 = build(c1);

     vector<string> c2;
     for (int i = 0; i < K-1; i++) {
        c2.push_back(S[i]);
     }

     int p = K-1;
     for (int i = K-1; i < N; i++) {
        ll x = ::stoll(S[i]);
        ll y = ::stoll(S[p]);
        if (x > y) p = i;
     }

     c2.push_back(S[p]);
     string ans2 = build(c2);

     string ans{};
    
     auto gg = [&](const auto& s1, const auto& s2) {
        if (s1.size() != s2.size())
            return s1.size() > s2.size();
        return s1 > s2;
     };

     if (gg(ans1, ans2)) {
        ans = ans1;
     } else {
        ans = ans2;
     }
     cout << ans << '\n';

    return 0;
}