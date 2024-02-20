#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 50 + 5, MAXT = 200 + 5, INF = 1e9;

int has_train[MAXT][MAXN][2], t[MAXN];
int n, T;
int dp[MAXT][MAXN];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    for (int kase = 1; ; kase++) {
        cin >> n;
        if (n == 0) break;
        printf("Case Number %d: ", kase);
        
        cin >> T;
        for (int i = 1; i <= n - 1; i++) {
            cin >> t[i];
        }
        
        memset(has_train, 0, sizeof(has_train));
        int M1, M2, d;
        cin >> M1;
        for (int i = 1; i <= M1; i++) {
            cin >> d;
            has_train[d][1][0] = 1;
            for (int j = 1; j <= n - 1; j++) {
                if (d + t[j] <= T) has_train[d + t[j]][j + 1][0] = 1;
                d += t[j];
            }
        }
        
        cin >> M2;
        for (int i = 1; i <= M2; i++) {
            cin >> d;
            has_train[d][n][1] = 1;
            for (int j = n - 1; j >= 1; j--) {
                if (d + t[j] <= T) has_train[d + t[j]][j][1] = 1;
                d += t[j];
            }
        }
        
        for (int i = 1; i <= n - 1; i++) dp[T][i] = INF;
        dp[T][n] = 0;
        
        for (int i = T - 1; i >= 0; i--) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i + 1][j] + 1;
                if (j < n && has_train[i][j][0] && i + t[j] <= T) {
                    dp[i][j] = min(dp[i][j], dp[i + t[j]][j + 1]);
                } 
                if (j > 1 && has_train[i][j][1] && i + t[j - 1] <= T) {
                    dp[i][j] = min(dp[i][j], dp[i + t[j - 1]][j - 1]);
                }
            }
        }
        
        if (dp[0][1] >= INF) cout << "impossible" << endl;
        else cout << dp[0][1] << endl;
    }


    return 0;
}