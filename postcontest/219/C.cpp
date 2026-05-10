#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    auto jorgee = [&]() -> void {
        i64 H, W; cin >> H >> W;
        int N; cin >> N;
        vector<pair<i64, i64>> d(N);
        for (int i = 0; i < N; i++) {
            i64 A, B; cin >> A >> B;
            d[i] = {A, B};
        }
        sort(d.begin(), d.end());
        i64 l = 0;
        i64 b = 0;
        vector<i64> diff;
        int i = 0;
        while (i < N) {
            i64 row = d[i].first;
            vector<i64> cols;
            while (i < N && d[i].first == row) {
                cols.push_back(d[i].second);
                i++;
            }
            sort(cols.begin(), cols.end());
            i64 rr = cols.back();
            l += 2 * (rr - 1);
            i64 mxgap = 0;
            mxgap = max(mxgap, cols[0] - 1); 
            for (int j = 0; j+1 < (int)cols.size(); j++) {
                mxgap = max(mxgap, cols[j+1] - cols[j]);
            }
            mxgap = max(mxgap, W - cols.back());
            i64 ai = 2 * (W - 1) - 2 * mxgap;
            b += ai;
            diff.push_back((W-1) - ai);
        }
        i64 ans = l;
        sort(diff.begin(), diff.end());
        i64 cur = 0;
        for (int k = 1; k <= (int)diff.size(); k++) {
            cur += diff[k-1];
            if (k % 2 == 0) {
                ans = min(ans, b + cur);
            }
        }
        cout << ans << '\n';
    }; jorgee();
    return 0;       
}