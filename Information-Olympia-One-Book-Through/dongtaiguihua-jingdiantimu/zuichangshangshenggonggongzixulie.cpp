#include <bits/stdc++.h>

using namespace std;

int m1, a1[500], m2, a2[500], f[500][500], b1[500][500], b2[500][500], max1, max2;

void print(int a, int b) {
    if (b1[a][b] == 0 && b2[a][b] == 0) {
        printf("%d ", a1[a]);
        return;
    }
    
    print(a - b1[a][b], b - b2[a][b]);
    printf("%d ", a1[a]);

}

int main() {
    cin >> m1;
    for (int i = 1; i <= m1; i++) cin >> a1[i];
    cin >> m2;
    for (int i = 1; i <= m2; i++) cin >> a2[i];
    
    for (int i = 1; i <= m1; i++) {
        for (int j = 1; j <= m2; j++) {
            f[i][j] = 1;
            if (f[i][j] < f[i][j - 1]) {
                f[i][j] = f[i][j - 1];
                b1[i][j] = 0;
                b2[i][j] = 1;
            }
            if (f[i][j] < f[i - 1][j]) {
                f[i][j] = f[i - 1][j];
                b1[i][j] = 1;
                b2[i][j] = 0;
            }
            
            if (a1[i] == a2[j]) {
                for (int k1 = 1; k1 < i; k1++) {
                    for (int k2 = 1; k2 < j; k2++) {
                        if (a1[i - k1] == a2[j - k2] && a1[i] > a1[i - k1] && f[i - k1][j - k2] + 1 > f[i][j]) {
                            f[i][j] = f[i - k1][j - k2] + 1;
                            b1[i][j] = k1;
                            b2[i][j] = k2;
                        }
                    }
                }
            }
            
            if (f[max1][max2] < f[i][j]) max1 = i, max2 = j;
        }
    }
    printf("%d\n", f[max1][max2]);
    
    if (f[max1][max2] != 0) {
        print(max1, max2);
    }
    printf("\n");
    

    return 0;
}