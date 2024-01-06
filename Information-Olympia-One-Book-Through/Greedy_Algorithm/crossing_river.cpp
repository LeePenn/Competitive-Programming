#include <bits/stdc++.h>

using namespace std;

int a[10001], dp[10001];
int t, n;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        sort(a + 1, a + n + 1);
        dp[1] = a[1];
        dp[2] = a[2];
        for (int i = 3; i <= n; i++) {
            dp[i] = min(dp[i - 1] + a[1] + a[i], dp[i - 2] + a[1] + a[i] + a[2] * 2);
        }
        cout << dp[n] << endl;
    }


    return 0;
}