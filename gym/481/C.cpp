#include <iostream>
#include <string>
#include <unordered_map>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int Q; std::cin >> Q;
    std::unordered_map<std::string, int> ids;
    while (Q--) {
        std::string s; std::cin >> s;
        auto [it, inserted] = ids.try_emplace(s, ids.size() + 1);
        std::cout << it->second << '\n';
    }
    return 0;
}
