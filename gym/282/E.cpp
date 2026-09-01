#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

template<typename T> using V = vector<T>;
#define vi V<int>

struct DSU {
    vi e; void init(int n) { e = vi(n,-1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool unite(int x, int y) {
        x = get(x), y = get(y); 
        if (x == y) return false;
        if (e[x]>e[y]) swap(x,y);
        e[x] += e[y]; e[y] = x;
        return true;
    }
};

struct edge {
    int u, v;
    ll w;
};

ll modpow(ll a, ll e, ll mod) { 
    ll r = 1;
    a %= mod;
    while (e) {
        if (e&1) r = r * a % mod;
        a = a * a % mod;
        e >>= 1;
    } 
    return r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<ll> A(n); for (int i = 0; i < n; ++i) cin >> A[i];
    vector<edge> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; j++) { 
            ll w = (modpow(A[i], A[j], m) + modpow(A[j], A[i], m)) % m;
            edges.push_back({i,j,w});
        }
    }
    sort(edges.begin(), edges.end(), [&](auto& a, auto& b){ return a.w > b.w; });
    DSU d;
    d.init(n);
    ll mst_sum = 0;
    for (auto& e : edges) {
        if (d.unite(e.u, e.v)) mst_sum += e.w;
    }
    cout << mst_sum << '\n';
    return 0;
}