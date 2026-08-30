#include <iostream>
#include <vector>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, K; cin >> N >> K;
    vector<mint> fact(N+1), invfact(N+1);
    fact[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fact[i] = fact[i-1] * i;
    }
    invfact[N] = fact[N].inv();
    for (int i = N; i >= 1; i--) {
        invfact[i-1] = invfact[i] * i;
    }

    auto C = [&](int n, int r) -> mint {
        if (n < 0 || r < 0 || r > n) return 0;
        return fact[n] * invfact[r] * invfact[n-r];
    };

    mint sum = 0;
    mint sqsum = 0;

    for (int i = 0; i < N; ++i) {
        ll x; cin >> x;
        mint a = x;
        sum += a;
        sqsum += a * a;
    }
    mint ans = C(N-1, K-1) * sqsum + C(N-2, K-2) * (sum * sum - sqsum);
    cout << ans.val() << '\n';

    return 0;
}
