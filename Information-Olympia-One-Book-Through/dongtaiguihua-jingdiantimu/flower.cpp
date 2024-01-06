#include <bits/stdc++.h>

using namespace std;

int n, v, a[100][100], f[100][100];

void print(int i, int j) {
    if (j == 0) {
        return;
    }
    while (i >= 1) {
        if (f[i][j] == f[v][n]) {
            f[v][n] -= a[j][i];
            print(i - 1, j - 1);
            printf("%d ", i);
            break;
        }
        i--;
    }

}

int main() {
    cin >> n >> v;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= v; j++) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= min(i, n); j++) {
            f[i][j] = 0;
            for (int k = j - 1; k <= i - 1; k++) {
                f[i][j] = max(f[i][j], f[k][j - 1] + a[j][i]);
            }
        }
    }
    cout << f[v][n] << endl;
    print(v, n);
    printf("\n");
    
    return 0;
}