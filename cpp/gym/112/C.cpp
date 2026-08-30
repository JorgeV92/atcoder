#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int p; std::cin >> p;
        p--;
        g[p].push_back(i);
    }
    std::vector<int> sz(n,1);
    std::vector<ll> f(n);

    [&](this auto&& self, int v) -> void {
        ll neg = 0;
        ll nonneg = 0;
        std::vector<ll> odds;
        for (int u : g[v]) {
            self(u);
            sz[v] += sz[u];
            if (sz[u] % 2 == 1) {
                odds.push_back(f[u]);
            } else if (f[u] < 0) {
                neg += f[u];
            } else {
                nonneg += f[u];
            }
        }
        std:sort(odds.begin(), odds.end());
        ll cur = 1;
        cur += neg;
        for (int i = 0; i < (int)odds.size(); ++i) {
            if (i % 2 == 0) {
                cur += odds[i];
            } else {
                cur -= odds[i];
            }
        }
        if (odds.size() % 2 == 0) {
            cur += nonneg;
        } else cur -= nonneg;
        f[v] = cur;
    }(0);

    std::cout << (n + f[0]) / 2 << '\n';
    return 0;
}