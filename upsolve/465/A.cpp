#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int A, B; cin >> A >> B;
    cout << (3*A > B * 2 ? "Yes" : "No") << '\n';
    return 0;
}