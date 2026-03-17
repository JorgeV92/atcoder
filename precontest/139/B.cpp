#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;

    int cnt = 0;
    int so = 1;
    while(so < B) {
        so += (A-1);
        cnt++;
    }
    cout << cnt << '\n';

    return 0;
}
