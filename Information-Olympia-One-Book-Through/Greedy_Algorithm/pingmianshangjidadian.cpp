#include <bits/stdc++.h>

using namespace std;

int n, a[1000][1000];

int main() {
    cin >> n;
    int mxx = -100000, mxy = -100000;
    int x, y;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        a[x][y] = 1;
        mxx = max(mxx, x);
        mxy = max(mxy, y);
    }
    
    int cnt = 0;
    int ans[1000][2];
    int m = 0;
    for (int i = mxx; i >= 0; i--) {
        for (int j = mxy; j > m; j--) {
            if (a[i][j] == 1) {
                m = j;
                cnt++;
                ans[cnt][0] = i;
                ans[cnt][1] = j;
            }
        }
    }
    
    printf("(%d,%d)", ans[1][0], ans[1][1]);
    for (int i = 2; i <= cnt; i++) {
        printf(",(%d,%d)", ans[i][0], ans[i][1]);
    }

    return 0;
}