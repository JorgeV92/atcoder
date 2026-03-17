#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <string>

using namespace std;

#define OUT(x) cout << x << '\n';
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++) 
#define FORE(i,a,b) for(int i = (a); i <= (b); i++)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

using ll = long long;

int dp[3003][3003];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    FORE(i,1,n) {
        FORE(j,1,m) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }


    string out = "";
    int l = n, r = m;
    while (l > 0 && r > 0) {
        if (s[l-1] == t[r-1]) {
            out += s[l-1];
            l--; r--;
        } else {
            if (dp[l-1][r] > dp[l][r-1]) {
                l--;
            } else {
                r--;
            }
        }
    }

    reverse(out.begin(),out.end());

    OUT(out);

    return 0;
}