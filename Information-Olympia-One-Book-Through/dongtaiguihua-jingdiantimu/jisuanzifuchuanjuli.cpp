#include <bits/stdc++.h>

using namespace std;

char a[1000], b[1000];
int l1, l2, f[1000][1000];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s %s", a, b);
        l1 = strlen(a), l2 = strlen(b);
        for (int i = l1; i >= 1; i--) a[i] = a[i - 1];
        for (int i = l2; i >= 1; i--) b[i] = b[i - 1];
        memset(f, 127, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1];
                else {
                    f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
                }
            }
        }
        printf("%d\n", f[l1][l2]);
    
    }

    return 0;
}