#include <iostream>
#include <vector>
#include <string>
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    std::string s; std::cin >> s;
    int n = s.size();
    if (s[n-1] == 'e') s+= 'r';
    else s += "er";
    std::cout << s << '\n';
    return 0;
}