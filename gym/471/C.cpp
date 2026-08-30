#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    set<ll> S;
    for (int i = 0; i < N; ++i) {
        ll x; cin >> x;
        S.insert(x);
    }
    ll pos = 0, ans = 0;
    
    while (!S.empty()) {
        auto it = S.lower_bound(pos);
        ll nxt;
        if (it == S.begin()) {
            nxt = *it;
        } else if (it == S.end()) {
            nxt = *prev(it);
        } else {
            ll r = *it;
            ll l = *prev(it);
            ll ld = pos - l;
            ll rd = r - pos;
            if (ld <= rd) {
                nxt = l;
            } else {
                nxt = r;
            }
        }
        ans += abs(nxt - pos);
        pos = nxt;
        S.erase(nxt);
    }
    cout << ans << '\n';
    
    return 0;
}