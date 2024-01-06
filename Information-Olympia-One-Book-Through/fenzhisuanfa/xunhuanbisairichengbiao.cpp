#include <bits/stdc++.h>

using namespace std;

int m, a[1024][1024];

int main() {
    cin >> m;
    int n = 0;
    int x = 0;
    a[1][1] = 1;
    while (n < m) {
        if (x == 0) x = 1;
        else x *= 2;
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= x; j++) {
                a[i][j + x] = a[i][j] + x;
            }
        }
        for (int i = x + 1; i <= x * 2; i++) {
            for (int j = 1; j <= x; j++) {
                a[i][j] = a[i - x][j + x];
            }
            for (int j = x + 1; j <= x * 2; j++) {
                a[i][j] = a[i - x][j - x];
            }
        }
        n++;
    }
    
    for (int i = 1; i <= x * 2; i++) {
        for (int j = 1; j <= x * 2; j++) {
            printf("% 4d", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}