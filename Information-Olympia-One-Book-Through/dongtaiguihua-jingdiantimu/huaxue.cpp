#include <bits/stdc++.h>

using namespace std;

int r, c, a[100][100], f[100][100];

int work(int p, int q) {
    if (f[p][q] > 0) return f[p][q];
    int temp = 0;
    if (p - 1 >= 1 && a[p - 1][q] < a[p][q]) temp = max(temp, work(p - 1, q));
    if (p + 1 <= r && a[p + 1][q] < a[p][q]) temp = max(temp, work(p + 1, q));
    if (q - 1 >= 1 && a[p][q - 1] < a[p][q]) temp = max(temp, work(p, q - 1));
    if (q + 1 <= c && a[p][q + 1] < a[p][q]) temp = max(temp, work(p, q + 1));
    f[p][q] = temp + 1;
    return f[p][q];
}

int main() {
    cin >> r >> c;
    for (int i = 1; i <= r; i++) 
        for (int j = 1; j <= c; j++) cin >> a[i][j];
        
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) work(i, j);
    }
    
    int ans = 0;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) ans = max(ans, f[i][j]);
    }
    cout << ans << endl;
    
    return 0;
}