#include <bits/stdc++.h>

using namespace std;

int a[100], b, c[100], lena, lenc;
char stra[100];

int main() {
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    scanf("%s", stra);
    scanf("%d", &b);
    lena = strlen(stra);
    for (int i = 1; i <= lena; i++) a[i] = stra[i - 1] - 48;
    int x = 0;
    for (int i = 1; i <= lena; i++) {
        c[i] = (x * 10 + a[i]) / b;
        x = (x * 10 + a[i]) % b;
    }
    lenc = 1;
    while (c[lenc] == 0 && lenc < lena) lenc++;
    for (int i = lenc; i <= lena; i++) cout << c[i];
    cout << endl;

    return 0;
}