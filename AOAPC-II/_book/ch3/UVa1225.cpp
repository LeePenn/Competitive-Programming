// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 10004;
int n;
int f[N][10];

int get(int x, int d) {
    int ans = 0;
    while (x) {
        if (x % 10 == d) ans++;
        x /= 10;
    }
    return ans;
}

int main() {
    for (int i = 0; i <= 9; i++) {
        f[1][i] = i == 1;
    }
    for (int i = 2; i < N; i++) {
        for (int j = 0; j <= 9; j++) {
            f[i][j] += f[i - 1][j] + get(i, j);
        }
    }
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        for (int i = 0; i <= 8; i++) {
            printf("%d ", f[x][i]);
        }
        printf("%d\n", f[x][9]);
    }
    return 0;
}