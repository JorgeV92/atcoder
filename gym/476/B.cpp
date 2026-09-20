#include <iostream>
#include <vector>
#include <string>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int N; std::cin >> N;
    std::string S, T; std::cin >> S >> T;
    int cnt = 0, e = 0; 
    for (int i = 0; i < N; ++i) {
        if (S[i] != T[i]) cnt++;
        if (T[i] == '*') e++;
    }
    if (cnt <= e) std::cout << "Yes\n";
    else std::cout << "No\n";
    return 0;
}