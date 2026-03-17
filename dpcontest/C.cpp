#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>

using namespace std;

#define OUT(x) cout << x << '\n';
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

using ll = long long;

const int inf = 1e9;
const int MAXN = 1e5 + 8;

ll A[MAXN][3];
ll dp[MAXN][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j : {0,1,2}) {
            for (int k : {0,1,2}) {
                if (j == k) continue;
                chmax(dp[i+1][k], dp[i][j] + A[i][k]);
            }
        }
    }

    ll res =0 ;
    for (int i = 0; i < 3; i++) {
        chmax(res, dp[n][i]);
    }
    OUT(res);

    return 0;
}