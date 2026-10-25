#include <iostream>
#include <vector>
struct Edge {
    int to, digit;
};
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    const int MOD = 998244353;
    int N, M; std::cin >> N >> M;
    std::vector<std::vector<Edge>> graph(N + 1);
    while (M--) {
        int A, B, C; std::cin >> A >> B >> C;
        graph[A].push_back({B, C});
    }
    std::vector<int> ans(N + 1);
    std::vector<bool> visited(N + 1);
    std::vector<std::vector<int>> groups = {{1}};
    visited[1] = true;
    while (!groups.empty()) {
        std::vector<std::vector<int>> nextGroups;
        for (const auto &group : groups) {
            for (int digit = 1; digit <= 9; digit++) {
                std::vector<int> next;
                for (int u : group) {
                    for (const auto &[v, c] : graph[u]) {
                        if (c != digit || visited[v]) continue;
                        visited[v] = true;
                        ans[v] = (ans[u] * 10LL + c) % MOD;
                        next.push_back(v);
                    }
                }
                if (!next.empty()) nextGroups.push_back(std::move(next));
            }
        }
        groups = std::move(nextGroups);
    }
    for (int v = 2; v <= N; v++) std::cout << ans[v] << '\n';
    return 0;
}
