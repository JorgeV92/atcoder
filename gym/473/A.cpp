#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n); for (int i = 0; i < n; ++i) cin >>a[i];
    int sum=0; for (int i=n/2; i<n; i++) sum+=a[i];
    cout<<sum<<'\n';
    return 0;
}