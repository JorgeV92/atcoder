#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>

using namespace std;

#define OUT(x) cout << x << '\n';
#define all(x) (x).begin(), (x).end()
#define FOR(a,b) for(int i = (a); i < (b); i++) 
#define FORE(a,b) for(i = (a); i <= (b); i++)
#define ROF(a,b) for(int i = (a); i >= (b); i--)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

using ll = long long;

const int inf = 1e9;
const ll linf = 1e18;

const int MAXN = 106;

ll weights[MAXN];
ll values[MAXN];
ll dp[MAXN][100100];
ll f[100100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, W;
    cin >> N >> W;
    
    for (int i = 0; i < N; i++) {
        cin >> weights[i] >> values[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= W; j++) {
            if (j - weights[i] >= 0)
                chmax(dp[i+1][j], dp[i][j-weights[i]] + values[i]);
            chmax(dp[i+1][j], dp[i][j]);
        }
    }

    // or
    for (int i = 1; i <= N; i++) {
        for (int j = W; j >= weights[i-1]; j--) {
            chmax(f[j], f[j-weights[i-1]] + values[i-1]);
        }
    }

    // OUT(dp[N][W]);
    OUT(f[W]);
    

    return 0;
}