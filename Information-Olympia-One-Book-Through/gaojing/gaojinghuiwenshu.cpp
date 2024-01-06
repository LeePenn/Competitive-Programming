#include <bits/stdc++.h>

using namespace std;

int a[1000], b[1000], c[1000], n;
char str[1000];

const int MAX_T = 30;

void mirror(int a[], int b[]) {
    for (int i = 1; i <= a[0]; i++) b[i] = a[a[0] - i + 1];
    b[0] = a[0];
    
    return;
}

void init() {
    scanf("%s", str);
    scanf("%d", &n);
    a[0] = strlen(str);
    for (int i = 1; i <= a[0]; i++) {
        if (str[a[0] - i] >= '0' && str[a[0] - i] <= '9') a[i] = str[a[0] - i] - '0';
        else a[i] = str[a[0] - i] - 'A';
    }
    mirror(a, b);
    return;
}

bool check(int a[]) {
    for (int i = 1; i <= a[0] / 2; i++) {
        if (a[i] != a[a[0] - i + 1]) return false;
    }
    return true;
}

void gaoadd(int a[], int b[], int n) {
    int lenc = 1;
    int x = 0;
    memset(c, 0, sizeof(c));
    while (lenc <= a[0] || lenc <= b[0]) {
        c[lenc] = a[lenc] + b[lenc] + x;
        x = c[lenc] / n;
        c[lenc] %= n;
        lenc++;
    }
    c[lenc] = x;
    if (c[lenc] == 0) lenc--;
    c[0] = lenc;
    memcpy(a, c, sizeof(c));
    mirror(a, b);

    return;
}

int main() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    
    init();
    int t = 0;
    while (t < MAX_T) {
        if (check(a)) {
            cout << t << endl;
            return 0;
        }
        gaoadd(a, b, n);
        t++;
    }

    return 0;
}