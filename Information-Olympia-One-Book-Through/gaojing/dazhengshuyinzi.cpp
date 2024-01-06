#include <bits/stdc++.h>

using namespace std;

int a[1000], b[1000], c[1000], k;
char str[1000];

int main() {
    scanf("%s", str);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    a[0] = strlen(str);
    for (int i = 1; i <= a[0]; i++) a[i] = str[i - 1] - '0';
    memcpy(c, a, sizeof(a));
    k = 2;
    while (k < 10) {
        int x = 0;
        for (int i = 1; i <= a[0]; i++) {
            b[i] = (x * 10 + a[i]) / k;
            x = (x * 10 + a[i]) % k;
        }
        if (x == 0) cout << k << ' ';
        memcpy(a, c, sizeof(c));
        k++;
    }
    cout << endl;

    return 0;
}