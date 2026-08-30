#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;cin>>n;
    vector<int> f(101);
    for (int i=0;i<n;i++) { int x; cin>>x; f[x]++; }
    for (int i = 0; i<101; i++) {
        while (f[i] >= 2) f[i] -= 2;
    }
    int sum=0; 
    for (int i=0;i<101;i++) {
        if (f[i]) sum+= i;
    }
    cout<<sum<<'\n';
    return 0;   
}