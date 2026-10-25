#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int N, M, S, T; std::cin >> N >> M >> S >> T;
    std::vector<std::vector<int>> graph(N + 1);
    std::vector<int> smallest(N + 1, N + 1);
    while (M--) {
        int A, B; std::cin >> A >> B;
        graph[A].push_back(B);
        smallest[A] = std::min(smallest[A], B);
    }
    const int INF = 1e9;
    std::vector<int> dist(N + 1, INF);
    std::deque<int> dq;
    dist[S] = 0;
    dq.push_front(S);
    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        int d = dist[u];
        for (int v : graph[u]) {
            int w = v == smallest[u] ? 0 : 1;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                if (w == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
    std::cout << (dist[T] == INF ? -1 : dist[T]) << '\n';
    return 0;
}
