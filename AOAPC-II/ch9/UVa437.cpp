#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 30;
int d[MAXN][3], blocks[MAXN][3];
int n;

void getDimension(int *v, int i, int j) {
    int idx = 0;
    for (int i1 = 0; i1 < 3; i1++) {
        if (i1 != j) v[idx++] = blocks[i][i1];
    }
}

int dp(int i, int j) {
    int &ans = d[i][j];
    if (ans > 0) return ans;

    ans = 0;
    int v[2], v2[2];
    getDimension(v, i, j);
    for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 < 3; j1++) {
            getDimension(v2, i1, j1);
            if (v[0] > v2[0] && v[1] > v2[1]) {
                ans = max(ans, dp(i1, j1));
            }
        }
    }
    
    return ans = ans + blocks[i][j];
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int kase = 0;
    while (cin >> n && n) {
        kase++;
        for (int i = 0; i < n; i++) {
            cin >> blocks[i][0] >> blocks[i][1] >> blocks[i][2];
            sort(blocks[i], blocks[i] + 3);
        }
        
        int ans = 0;
        memset(d, 0, sizeof(d));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                ans = max(ans, dp(i, j));
            }
        }
        
        cout << "Case " << kase << ": maximum height = " << ans << endl;
    }
    


    return 0;
}