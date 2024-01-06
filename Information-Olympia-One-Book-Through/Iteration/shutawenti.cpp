#include <bits/stdc++.h>

using namespace std;

int n, a[100][100];

int main() {
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = n - 1; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            if (a[i + 1][j] > a[i + 1][j + 1]) a[i][j] += a[i + 1][j];
            else a[i][j] += a[i + 1][j + 1];
        }
    }
    cout << a[1][1] << endl;


    return 0;
}