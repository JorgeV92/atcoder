#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{};
    cin >> n;
    vector<int> X(n);
    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }
    sort(X.begin(), X.end());
    int ans = inf;
    for (int p = 1; p< 101; p++) {
        int total =0;
        for (int j = 0; j < n; j++) 
            total += (X[j] - p) * (X[j]-p);
        ans = min(ans, total);
    }
    cout << ans << '\n';

    return 0;
}