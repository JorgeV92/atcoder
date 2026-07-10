#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int64_t N; cin >> N;
    if (N <= 1000-1) {
        ;
    } else if (N >= 1000 && N <= 10000-1) {
         N = (N/10) * 10;
    } else if (N >= 10000 && N <= 100000-1) {
        N  = (N/100) * 100;
    } else if (N >= 100000 && N <= 1000000-1) {
        N = (N/1000) * 1000;
    } else if (N >= 1000000 && N <= 10000000-1) {
        N = (N/10000) * 10000;
    } else if (N >= 10000000 && N <= 100000000-1) {
        N = (N/100000) * 100000; 
    } else if (N >= 100000000 && N <= 1000000000-1) {
        N = (N/1000000) * 1000000;
    }
    cout << N << '\n';
    return 0;
}   