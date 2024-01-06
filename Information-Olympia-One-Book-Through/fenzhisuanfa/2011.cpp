#include <bits/stdc++.h>

using namespace std;

int t, a[10000], b[200];
char ch[200];

int main() {
    int cnt = 0, q = 2011;
    do {
        cnt++;
        a[cnt] = q;
        q = q * 2011 % 10000;
    } while (q != 2011);
    a[0] = a[cnt];
    
    scanf("%d", &t);
    while (t--) {
        scanf("%s", ch);
        int len = strlen(ch);
        for (int i = 0; i < len; i++) {
            b[i + 1] = ch[i] - '0';
        }
        int x = 0;
        for (int i = 1; i <= len; i++) {
            x = (x * 10 + b[i]) % cnt;
        }
        printf("%d\n", a[x]);
    }
    
    return 0;
}