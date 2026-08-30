#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin>>n >> k;
    unordered_map<int,int> mp;
    for (int i=0; i<n; i++) { int x; cin>>x; mp[x]++; }
    auto it = max_element(mp.begin(), mp.end(), [&](auto& a, auto& b) { return a.second < b.second; } );
    int mx = -1;
    if (it != mp.end()) mx = it->second;
    int cnt = 0;
    for (const auto& [k,v] : mp) {
        if (v+1 >= mx) cnt++;
    }
    cout<<cnt<<'\n';

    return 0;
}