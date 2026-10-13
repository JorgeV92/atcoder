#include <iostream>
#include <vector>
using namespace std;

using i64 = long long;

template <class S, S (*op)(S, S), S (*e)()>
struct SegTree {
    int n, sz;
    vector<S> d;

    SegTree() : n(0), sz(0) {}
    explicit SegTree(int n) : SegTree(vector<S>(n, e())) {}
    explicit SegTree(const vector<S>& v) : n((int)v.size()) {
        sz = 1;
        while (sz < n) sz <<= 1;
        d.assign(2 * sz, e());
        for (int i = 0; i < n; i++) d[sz + i] = v[i];
        for (int i = sz - 1; i >= 1; i--) pull(i);
    }

    void set(int p, S x) {              
        p += sz;
        d[p] = x;
        for (p >>= 1; p >= 1; p >>= 1) pull(p);
    }

    S get(int p) const { return d[p + sz]; }

    S prod(int l, int r) const {        
        S sml = e(), smr = e();
        l += sz; r += sz;
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1; r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; } 

private:
    void pull(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

long long op(long long a, long long b) { return min(a, b); }
long long e() { return (long long)4e18; }

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, Q; cin >>N>>Q;
    std::vector<i64> A(N); for (auto& a : A) cin >>a;
    int size=1;
    while (size<N) size<<=1;
    SegTree<long long, op, e> seg(A);
    while (Q--) {
        int t; cin >>t;
        if (t == 1) {
            int i; i64 x;
            cin >>i>>x;
            seg.set(i-1,x);
        } else {
            int l, r;
            cin >>l>>r;
            cout <<seg.prod(l-1,r) << '\n';
        }
    }
    return 0;
}