#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int X, Y, L, R, A, B; cin >> X >> Y >> L >> R >> A >> B;
    int x = max(0, min(B, R) - max(L, A));
    int t = B-A;
    cout <<  x * X + (t - x) * Y << '\n';
    return 0;   
}

/*
     7   21
     9   17
*/