#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std; 

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin>>n>>k;
    vector<int> A(n);
    function<void(int,int)> dfs = [&](int i, int sum) -> void {
        if (i == n-1) {
            int r = k-sum;
            if (r % n == 0) {
                A[i] = r/n;
                for (int i = 0; i < n; ++i) {
                    cout << A[i] << ' '; 
                }
                cout<<'\n';
            }
            return;
        }
        int c = i + 1;
        for (int x = 0; sum+x*c <= k; x++) {
            A[i] = x;
            dfs(i+1,sum+x*c);
        }
    }; dfs(0,0);

    return 0;
}