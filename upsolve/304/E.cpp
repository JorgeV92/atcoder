#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <set>
using namespace std;
template<class T> using V = vector<T>;

#define vi V<int>

struct DSU {
    int n; vi e; void init(int _n) {n = _n; e = vi(n, -1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    int size(int x) { return -e[get(x)]; }
    bool sameSet(int x, int y) { return get(x) == get(y); }
    bool unite(int x, int y) {
        x = get(x), y = get(y); if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x; return true;
    } 
};

int N, M;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    DSU dsu;
    dsu.init(N+1);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        dsu.unite(a, b);
    }
    int K; cin >> K;
    set<pair<int,int>> bad;
    for (int i = 0; i < K; i++) {
        int x, y; cin >> x >> y;
        x = dsu.get(x), y = dsu.get(y); 
        if (x > y) swap(x, y);
        bad.insert({x, y});
    }
    int Q; cin >> Q;
    while (Q--) {
        int p, q; cin >> p >> q;
        p = dsu.get(p), q = dsu.get(q);
        if (p > q) swap(p, q);
        if (bad.count({p, q})) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}
