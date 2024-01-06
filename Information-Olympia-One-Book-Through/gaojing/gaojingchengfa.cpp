#include <bits/stdc++.h>

using namespace std;

int a[100], b[100], c[100], lena, lenb, lenc;
char stra[100], strb[100];

int main() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    
    scanf("%s", stra);
    scanf("%s", strb);
    lena = strlen(stra);
    lenb = strlen(strb);
    for (int i = 1; i <= lena; i++) a[i] = stra[lena - i] - 48;
    for (int i = 1; i <= lenb; i++) b[i] = strb[lenb - i] - 48;
    for (int i = 1; i <= lena; i++) {
        int x = 0;
        for (int j = 1; j <= lenb; j++) {
            c[i + j - 1] += a[i] * b[j] + x;
            x = c[i + j - 1] / 10;
            c[i + j - 1] %= 10;
        }
        c[i + lenb] += x;
    }
    lenc = lena + lenb;
    while (c[lenc] == 0 && lenc > 1) lenc--;
    for (int i = lenc; i > 0; i--) cout << c[i];
    cout << endl;

    return 0;
}