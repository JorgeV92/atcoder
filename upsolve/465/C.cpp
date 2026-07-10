#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <deque>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    string S; cin >> S;
    deque<int> dq;
    bool rev = false;
    for (int k = 1; k <= N; ++k) {
        if (!rev) dq.push_back(k);
        else dq.push_front(k);
        if (S[k-1] == 'o') rev = !rev;
    }
    vector<int> A(dq.begin(), dq.end());
    if (rev) reverse(A.begin(), A.end());
    for (int x : A) {
        cout << x << " ";
    }
    cout << '\n';
    return 0;
}