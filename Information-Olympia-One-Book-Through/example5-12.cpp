#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    int a[n][n], cur = 1, r = 0, c = n - 1;
    memset(a, 0, sizeof(a));
    a[r][c] = cur;
    while (cur < n * n) {
        // while use r + 1? for r can be n - 1 after while loop
        while (r + 1 < n && !a[r + 1][c]) a[++r][c] = ++cur;
        while (c - 1 >= 0 && !a[r][c - 1]) a[r][--c] = ++cur;
        while (r - 1 >= 0 && !a[r - 1][c]) a[--r][c] = ++cur;
        while (c + 1 < n && !a[r][c + 1]) a[r][++c] = ++cur;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(3) << a[i][j];
        }
        cout << endl;
    }

    return 0;
}