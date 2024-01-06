#include <bits/stdc++.h>

using namespace std;

int sum[100][100], n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> sum[i][j];
            sum[i][j] += sum[i][j - 1];
        }
    }
    
    int ans = -10000000;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int t = 0;
            for (int k = 1; k <= n; k++) {
                t += sum[k][j] - sum[k][i];
                if (ans < t) ans = t;
                if (t < 0) t = 0;
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}