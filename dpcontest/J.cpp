#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
using namespace std;

double dp[305][305][305];
int N;

double solve(int x, int y, int z) {
    if (x == 0 && y == 0 && z ==0) return 0.0;
    if (dp[x][y][z] >= 0) return dp[x][y][z];
    double res = 1.0 * N;
    if (x > 0) res += x * solve(x-1,y,z);
    if (y > 0) res += y * solve(x+1,y-1,z);
    if (z > 0) res += z * solve(x,y+1,z-1);
    res /= (x+y+z);
    return dp[x][y][z] = res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i< N; i++) {
        int x;
        cin >> x;
        if (x == 1) c1++;
        else if (x ==2) c2++;
        else c3++;
    }   
    memset(dp, -1, sizeof(dp));
    cout << fixed << setprecision(10) << solve(c1, c2, c3) << "\n";
    return 0;
}