#include <bits/stdc++.h>

using namespace std;

char a[200], b[200];
int l1, l2, f[200][200];

int main() {
    while (scanf("%s %s", a, b) == 2) {
        l1 = strlen(a); 
        l2 = strlen(b);
        for (int i = l1; i >= 1; i--) a[i] = a[i - 1];
        for (int i = l2; i >= 1; i--) b[i] = b[i - 1];
        f[0][0] = 0;
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
                else f[i][j] = max(f[i][j - 1], f[i - 1][j]);
            }
        }
        printf("%d\n", f[l1][l2]);
    }

    return 0;
}