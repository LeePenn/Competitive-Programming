#include <bits/stdc++.h>

using namespace std;

int a[10000], b[10000], len;
char str[10000];

int main() {
    scanf("%s", str);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    len = strlen(str);
    for (int i = 1; i <= len; i++) a[i] = str[i - 1] - '0';
    
    int x = 0;
    for (int i = 1; i <= len; i++) {
        b[i] = (x * 10 + a[i]) / 13;
        x = (x * 10 + a[i]) % 13;
    }
    int lenb = 1;
    while (lenb < len && b[lenb] == 0) lenb++;
    for (int i = lenb; i <= len; i++) cout << b[i];
    cout << endl;
    cout << x << endl;


    return 0;
}