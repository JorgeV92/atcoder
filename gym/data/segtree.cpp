// ============================================================
// Segment tree templates (0-indexed, half-open intervals [l, r))
//   SegTree     : point update / range query
//   LazySegTree : range update / range query
// Verified against brute force on randomized tests.
// ============================================================
#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// SegTree: point update, range query
//   op must be associative; e() is its identity: op(x, e()) == x
//   build O(n) | set, get, prod O(log n)
// ------------------------------------------------------------
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

    void set(int p, S x) {              // a[p] = x
        p += sz;
        d[p] = x;
        for (p >>= 1; p >= 1; p >>= 1) pull(p);
    }

    S get(int p) const { return d[p + sz]; }

    S prod(int l, int r) const {        // op over [l, r)
        S sml = e(), smr = e();
        l += sz; r += sz;
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1; r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; } // op over [0, n)

private:
    void pull(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

// ------------------------------------------------------------
// LazySegTree: range update, range query
//   S = value type   op: combine values          e(): identity of op
//   F = update type  mapping(f, s): apply update f to value s
//   composition(f, g): "apply g, then f" as one update
//   id(): identity update (mapping(id(), s) == s)
//   build O(n) | set, get, prod, apply O(log n)
// ------------------------------------------------------------
template <class S, S (*op)(S, S), S (*e)(),
          class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>
struct LazySegTree {
    int n, sz, h;
    vector<S> d;
    vector<F> lz;

    LazySegTree() : n(0), sz(0), h(0) {}
    explicit LazySegTree(int n) : LazySegTree(vector<S>(n, e())) {}
    explicit LazySegTree(const vector<S>& v) : n((int)v.size()) {
        sz = 1; h = 0;
        while (sz < n) { sz <<= 1; h++; }
        d.assign(2 * sz, e());
        lz.assign(sz, id());
        for (int i = 0; i < n; i++) d[sz + i] = v[i];
        for (int i = sz - 1; i >= 1; i--) pull(i);
    }

    void set(int p, S x) {              // a[p] = x
        p += sz;
        for (int i = h; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= h; i++) pull(p >> i);
    }

    S get(int p) {
        p += sz;
        for (int i = h; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {              // op over [l, r)
        if (l == r) return e();
        l += sz; r += sz;
        for (int i = h; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1; r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    void apply(int p, F f) {            // a[p] = mapping(f, a[p])
        p += sz;
        for (int i = h; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= h; i++) pull(p >> i);
    }

    void apply(int l, int r, F f) {     // apply f to all of [l, r)
        if (l == r) return;
        l += sz; r += sz;
        for (int i = h; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }
        int l2 = l, r2 = r;
        while (l2 < r2) {
            if (l2 & 1) all_apply(l2++, f);
            if (r2 & 1) all_apply(--r2, f);
            l2 >>= 1; r2 >>= 1;
        }
        for (int i = 1; i <= h; i++) {
            if (((l >> i) << i) != l) pull(l >> i);
            if (((r >> i) << i) != r) pull((r - 1) >> i);
        }
    }

private:
    void pull(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < sz) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

// ============================================================
// EXAMPLE CONFIGURATIONS
// ============================================================

// --- 1) Range minimum, point set ---
long long op_min(long long a, long long b) { return min(a, b); }
long long e_min() { return (long long)4e18; }
// SegTree<long long, op_min, e_min> seg(a);

// --- 2) Range sum, point set ---
long long op_sum(long long a, long long b) { return a + b; }
long long e_sum() { return 0; }
// SegTree<long long, op_sum, e_sum> seg(a);

// --- 3) Range gcd, point set ---
long long op_gcd(long long a, long long b) { return std::gcd(a, b); }
long long e_gcd() { return 0; }
// SegTree<long long, op_gcd, e_gcd> seg(a);

// --- 4) Range add, range sum (lazy) ---
// Node stores the sum AND the segment length so mapping can scale.
struct SumNode { long long sum, cnt; };
SumNode op_s(SumNode a, SumNode b) { return {a.sum + b.sum, a.cnt + b.cnt}; }
SumNode e_s() { return {0, 0}; }
SumNode map_add(long long f, SumNode s) { return {s.sum + f * s.cnt, s.cnt}; }
long long comp_add(long long f, long long g) { return f + g; }
long long id_add() { return 0; }
// vector<SumNode> v(n); for each i: v[i] = {a[i], 1};
// LazySegTree<SumNode, op_s, e_s, long long, map_add, comp_add, id_add> seg(v);

// --- 5) Range assign, range min (lazy) ---
// LLONG_MIN is the "no pending update" sentinel (values must never equal it).
long long map_assign(long long f, long long s) { return f == LLONG_MIN ? s : f; }
long long comp_assign(long long f, long long g) { return f == LLONG_MIN ? g : f; }
long long id_assign() { return LLONG_MIN; }
// LazySegTree<long long, op_min, e_min, long long, map_assign, comp_assign, id_assign> seg(a);