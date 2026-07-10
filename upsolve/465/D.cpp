#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using ll = long long;
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        ll X, Y, K; cin >> X >> Y >> K;
        ll ans = 0;
        while (X != Y) {
            if (X > Y) {
                X /= K;
            } else {
                Y /= K;
            }
            ans++;
        }
        cout << ans << '\n';
    }
    
    return 0;
}