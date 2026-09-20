#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int N; std::cin >> N;
    std::vector<int> a(N); for (int& x : a) std::cin >> x;;
    std::priority_queue<int,std::vector<int>,std::greater<int>> pq;
    for (int i = 0; i < 3; i++) pq.push(a[i]);
    std::cout << pq.top() << '\n';
    int i = 3;
    while (i < N) {
        pq.push(a[i]);
        while (pq.size() > 3) pq.pop();
        std::cout << pq.top() << '\n';
        i++;
    }
    return 0;
}