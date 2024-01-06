#include <bits/stdc++.h>

using namespace std;

int a[100], b[100], c[100], lena, lenb, lenc;
char stra[100], strb[100], n1[100];

int main() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    
    scanf("%s", stra);
    scanf("%s", strb);
    if (strlen(stra) < strlen(strb) || (strlen(stra) == strlen(strb) && strcmp(stra, strb) < 0)) {
        strcpy(n1, stra);
        strcpy(stra, strb);
        strcpy(strb, n1);
        cout << '-';
    }
    
    lena = strlen(stra);
    lenb = strlen(strb);
    for (int i = 1; i <= lena; i++) a[i] = stra[lena - i] - 48;
    for (int i = 1; i <= lenb; i++) b[i] = strb[lenb - i] - 48;
    lenc = 1;
    while (lenc <= lena || lenc <= lenb) {
        if (a[lenc] < b[lenc]) {
            a[lenc] += 10;
            a[lenc + 1]--;
        }
        c[lenc] = a[lenc] - b[lenc];
        lenc++;
    }
    while (c[lenc] == 0 && lenc > 1) lenc--;
    for (int i = lenc; i > 0; i--) cout << c[i];    
    cout << endl;

    return 0;
}