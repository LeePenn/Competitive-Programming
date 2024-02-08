// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, a[N], b[N];

int main() {
    int id = 1;
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        printf("Game %d:\n", id++);
        while (1) {
            int A = 0, B = 0;
            for (int i = 1; i <= n; i++) {
                scanf("%d", &b[i]);
                if (b[i] == a[i]) A++;
            }
            if (b[1] == 0) break;
            
            for (int i = 1; i <= 9; i++) {
                int c1 = 0, c2 = 0;
                for (int j = 1; j <= n; j++) {
                    if (a[j] == i) c1++;
                    if (b[j] == i) c2++;
                }
                B += min(c1, c2);
            }
            printf("    (%d,%d)\n", A, B - A);
        }
    }
    return 0;
}