#include <bits/stdc++.h>

using namespace std;

char s1[100], s2[100];
int f[100][100];

int main() {
    scanf("%s%s", s1, s2);
    int l1 = strlen(s1), l2 = strlen(s2);
    for (int i = l1; i >= 1; i--) s1[i] = s1[i - 1];
    for (int i = l2; i >= 1; i--) s2[i] = s2[i - 1];
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (s1[i] == s2[j]) f[i][j] = f[i - 1][j - 1];
            else {
                f[i][j] = max(f[i - 1][j - 1] + 1, f[i][j - 1]);
                f[i][j] = max(f[i][j], f[i - 1][j]);
            }
        }
    }
    printf("%d\n", f[l1][l2]);
    
    return 0;
    
}