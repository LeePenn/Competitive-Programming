#include <bits/stdc++.h>

using namespace std;

int n, a[1000][1000];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
        
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            a[i][j] += a[i][j - 1];
    
    int max1 = a[1][1];
    for (int c1 = 1; c1 <= n; c1++) {
        for (int c2 = c1; c2 <= n; c2++) {
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                sum += a[i][c2] - a[i][c1 - 1];
                if (sum > max1) max1 = sum;
                // from after i line
                sum = max(sum, 0);
            }
        }
    }
    cout << max1 << endl;
        
    return 0;   
}