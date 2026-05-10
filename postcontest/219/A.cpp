#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    auto jorgee = [&]() -> void {
        int N, M; cin >> N >> M;
        vector<string> strs(N);
        for (int i = 0; i < N; i++) {
            cin >> strs[i];
        }
        if (M < 20 && N == (1 << M)) {
            cout << "No" << '\n';
            return;
        }
        string ans{};
        vector<int> mark(N,1);
        for (int i = 0; i < M; i++) {
            int ones = 0, zeros = 0;
            for (int j = 0; j < N; j++) {
                if (mark[j] == 1) {
                    if (strs[j][i] == '1') ones++;
                    else zeros++;
                }
            }
            if (zeros < ones) ans.push_back('1');
            else ans.push_back('0');
            for (int j = 0; j < N; j++) {
                if (strs[j][i] == ans[i]) mark[j] = 0;
            }
        }
        cout << "Yes\n";
        cout << ans << '\n';
    }; jorgee();
    return 0;
}