#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

struct op {
    int r, c, s;
};

vector<op> ans;

void add(int r, int c, int s) {
    ans.push_back({r,c,s});
}

void solve(int H, int W, int top, int left) {
    if(H%2==0) {
        int ww = (W%2==0 ? W : W-1);
        for (int r = 0; r < H; r += 2) {
            for (int c = 0; c < ww; c += 2) {
                add(top+r, left+c, 1);
            }
        }
        return;
    } 
    
    if (W%2==0) {
        int hh = H-1;
        for (int r = 0; r < hh; r += 2) {
            for (int c = 0; c < W; c += 2) {
                add(top+r,left+c, 1);
            }
        }
        return;
    }

    if (H < W) {
        solve(H,W-2, top,left);
        for (int r = 0; r < H-1; r += 2) {
            add(top+r, left+W-2,1);
        }
        return;
    }

    if (H > W) {
        solve(H-2,W, top,left);
        for (int c = 0; c < W-1; c += 2) {
            add(top+H-2, left+c, 1);
        }
        return;
    }

    int n = H;
    if (n==1) return;
    if (n == 3) {
        add(top, left, 1);
        return;
    }

    add(top,left,n-1);
    for (int x = 1; x < n-2; x += 2) {
        add(top, left + x, 1);
        add(top+x, left+n-2, 1);
    }

    for (int x = 2; x < n-2; x += 2) {
        add(top+n-2, left+x, 1);
        add(top+x, left, 1);
    }

    solve(n-4, n-4, top+2, left+2);

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int H, W; cin >> H >> W;
        ans.clear();
        solve(H,W,1,1);
        cout << ans.size() << '\n';
        for (auto [r, c, s] : ans) {
            cout << r << ' ' << c << ' ' << s << '\n';
        }
    }
    return 0;
}