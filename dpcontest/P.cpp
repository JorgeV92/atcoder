#include <iostream>
#include <vector>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint1000000007;

int N;
vector<int> e[101010];
mint dp[101010][2];
void dfs(int cu, int pa=-1) {
    dp[cu][0] = dp[cu][1] = 1;
    for (auto to : e[cu]) {
        if (to != pa) {
            dfs(to, cu);
            dp[cu][0] *= dp[to][0] + dp[to][1];
            dp[cu][1] *= dp[to][0];
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(0);
    mint ans = dp[0][0] + dp[0][1];
    cout << ans.val() <<"\n";
    return 0;
}