#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <limits>
using namespace std;
using ll = long long;

vector<deque<ll>> q(5);

void mergeQueue(int a, int b, vector<pair<int,int>>& opt) {
    auto A = q[a];
    auto B = q[b];
    deque<ll> merged;
    while (!A.empty() || !B.empty()) {
        if (B.empty() || (!A.empty() && A.front() < B.front())) {
            merged.push_back(A.front());
            A.pop_front();
            opt.push_back({a+1,b+1});
        } else {
            merged.push_back(B.front());
            B.pop_front();
            opt.push_back({b+1, b+1});
        }
    }
    q[a].clear();
    q[b] = ::move(merged);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int Q; cin >> Q;
    const int limit[4]{1,9,81,729};

    Q = Q*2;
    while (Q--) {
        int t; cin >> t;
        if (t == -1) return 0;
        if (t == 1) {
            ll X; cin >> X;
            q[0].push_back(X);
            vector<pair<int,int>> opt;
            for (int i = 0; i < 4; i++) {
                if (q[i].size() >= limit[i]) {
                    mergeQueue(i, i+1, opt);
                }
            }
            cout << opt.size() << '\n';
            for (auto [a, b] : opt) {
                cout << a << ' ' << b << '\n';
            }
            cout << flush;
        } else {
            ll mn = numeric_limits<ll>::max();
            int best = -1;
            for (int i = 0; i < 5; i++) {
                if (!q[i].empty() && q[i].front() < mn) {
                    mn = q[i].front();
                    best = i;
                }
            }
            cout << best + 1 << '\n';
            cout << flush;
            q[best].pop_front();
        }
    }
    return 0;
}