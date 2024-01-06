#include <bits/stdc++.h>

using namespace std;

int a[10000], b[10000], c[10000], n;

void print(int a[]) {
    for (int i = a[0]; i > 0; i--) cout << a[i];
    cout << endl;

    return;
}

void addone(int b[]) {
    b[1]++;
    for (int i = 1; i <= b[0]; i++) {
        if (b[i] > 9) {
            b[i + 1]++;
            b[i] %= 10;
        }
    }
    if (b[b[0] + 1] != 0) b[0]++;
    
    return;
}

int main() {
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    
    a[0] = 1;a[1] = 1;
    b[0] = 1;b[1] = 1;
    int t = 1; 
    while (t <= n) {
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= b[0]; i++) {
            int x = 0;
            for (int j = 1; j <= a[0]; j++) {
                c[i + j - 1] += b[i] * a[j] + x;
                x = c[i + j - 1] / 10;
                c[i + j - 1] %= 10;
            }
            c[i + a[0]] += x;
        }
        c[0] = a[0] + b[0];
        while (c[0] > 0 && c[c[0]] == 0) c[0]--;
        memcpy(a, c, sizeof(c));
        addone(b);
        t++;
    }
    
    print(a);

    return 0;
}