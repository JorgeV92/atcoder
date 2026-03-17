#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <string_view>

using namespace std;

#define OUT(x) cout << x << '\n';
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++) 
#define FORE(i,a,b) for(i = (a); i <= (b); i++)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

using ll = long long;

struct Manacher {
    vector<int> p;
    string ms;
    string org;
    void init(string_view s) {
        org = string(s);
        ms = "@";
        for (char c : s) {
            ms += "#" + string(1,c);
        }
        ms += "#$";
        run();
    }   

    void run() {
        int n = ms.size();
        p.assign(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n-1; i++) {
            int mirror = l + r -i;
            if (i < r) {
                p[i] = min(r-i, p[mirror]);
            }
            while (ms[i+1+p[i]] == ms[i-1-p[i]]) {
                ++p[i];
            }
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    int getLongest(int cen, int odd) {
        int pos = 2* cen + 2 + !odd;
        return p[pos];
    }

    int lps() {
        int n = org.size();
        int maxLen = 1;
        int start = 0;

        for (int i = 0; i < n; i++) {
            int odd_len = getLongest(i,1);
            if (odd_len > maxLen) {
                maxLen = odd_len;
                start = i - maxLen / 2;
            }
            int even_len = getLongest(i,0);
            if (even_len > maxLen) {
                maxLen = even_len;
                start = i - maxLen / 2 + 1;
            }
        }

        return maxLen;
    }
};

void brute_force(const string& s) {
    int n = s.size();
    int ans = 1;

    auto is_palindrome = [](string_view t) {
        int n = t.size();
        for (int i = 0; i < n; i++) {
            if (t[i] != t[n-i-1]) 
                return false;
        }
        return true;
    };

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            string t = s.substr(i, j-i);
            if (is_palindrome(t)) 
                ans = max(ans, j-i);
        }
    }
    OUT(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    Manacher ma;
    ma.init(s);
    
    OUT(ma.lps());

    brute_force(s);

    return 0;
}