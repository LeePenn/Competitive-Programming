#include <bits/stdc++.h>

using namespace std;

int a[1000], b[1000], c[1000], n;

int main() {
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    
    a[0] = 1;a[1] = 1;
    b[0] = 1; b[1] = 2;
    int t = 0;
    while (t < n) {
        memset(c, 0, sizeof(c));
        c[0] = 0;
        for (int i = 1; i <= a[0]; i++) {
            int x = 0;
            for (int j = 1; j <= b[0]; j++) {
                c[i + j - 1] += a[i] * b[j] + x;
                x = c[i + j - 1] / 10;
                c[i + j - 1] %= 10;
            }
            c[i + b[0]] += x;
        }
        c[0] = a[0] + b[0];
        while (c[0] > 1 && c[c[0]] == 0) c[0]--;
        memcpy(a, c, sizeof(c));
        t++;
    }
    for (int i = c[0]; i > 0; i--) cout << c[i];
    cout << endl;


    return 0;
}