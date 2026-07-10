#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <map>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int64_t W, H, N; cin >> W >> H >> N;
    vector<int64_t> p(N), q(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i] >> q[i];
    }
    int64_t A; cin >> A;
    vector<int64_t> a(A); for (int i = 0; i < A; i++) cin >> a[i];
    int64_t B; cin >> B;
    vector<int64_t> b(B); for (int i = 0; i < B; ++i) cin >> b[i];
    a.push_back(W), b.push_back(H);
    map<pair<int64_t, int64_t>, int64_t> mp;
    for (int i = 0; i < N; ++i) {
        int64_t X = *lower_bound(a.begin(), a.end(), p[i]);
        int64_t Y = *lower_bound(b.begin(), b.end(), q[i]);
        mp[{X,Y}]++;
    }
    int64_t mn = N;
    int64_t mx = 0;
    for (auto& [k, cnt] : mp) {
        mx = max(mx, cnt);
    }
    if ((int64_t)mp.size() == (A+1) * (B+1)) {
        for (auto& [k, cnt] : mp) {
            mn = min(mn, cnt);
        }
    } else mn = 0;
    cout << mn << ' ' << mx << '\n';

    return 0;
} 