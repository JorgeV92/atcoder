#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>

using namespace std;

#define OUT(x) cout << x << '\n';
#define all(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i = (a); i < (b); i++) 
#define FORE(i,a,b) for(i = (a); i <= (b); i++)
#define ROF(i,a,b) for(int i = (a); i >= (b); i--)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return false;}
template<class T> inline bool chmin(T& a, T b) { if ( a > b) { a = b; return 1;} return false;}

using ll = long long;

const int MAXN = 105;
const int MAXV = 100105;
const ll inf = 1e18L;

ll weight[MAXN], value[MAXN];
ll dp[MAXN][MAXV];
ll f[MAXV];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W;
    cin >> N >> W;

    FOR(i,0,N) {
        cin >> weight[i] >> value[i];
    }

    FOR(i,0,MAXN) {
        FOR(j,0,MAXV) {
            dp[i][j] = inf;
        }
    }


    dp[0][0] = 0;
    FOR(i,0,N) {
        FOR(sum_v,0,MAXV) {
            if (sum_v - value[i] >= 0)
                chmin(dp[i+1][sum_v], dp[i][sum_v -value[i]] + weight[i]);
            chmin(dp[i+1][sum_v], dp[i][sum_v]);
        }
    }

    fill(f,f+MAXV, inf);
    f[0] = 0;
    FOR(i,1,N+1) {
        ROF(j,MAXV,value[i-1]) {
            chmin(f[j], f[j-value[i-1]] + weight[i-1]);
        }
    }

    ll ans = 0;
    for (int sum_v = 0; sum_v < MAXV; sum_v++) {
        if (dp[N][sum_v] <= W) 
            ans = sum_v;
    }

    OUT(ans);

    ll out = 0;
    FOR(sum_v,0,MAXV) {
        if (f[sum_v] <= W) {
        out = sum_v;
        }
    }

    OUT(out);

    return 0;
}