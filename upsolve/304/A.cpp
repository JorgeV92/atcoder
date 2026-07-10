#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, string>> na(n);
    for (int i = 0; i < n; ++i) {
        string s; int v; cin >> s >> v;
        na[i] = {v, s};
    }
    int id = min_element(na.begin(), na.end()) - na.begin(); 
    for (int i = 0; i  < n; i++) {
        int j = (id + i) % n;
        cout << na[j].second << '\n';
    }    
    return 0;
}