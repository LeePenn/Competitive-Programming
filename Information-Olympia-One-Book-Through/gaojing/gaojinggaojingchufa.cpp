#include <bits/stdc++.h>

using namespace std;

int a[100], b[100], c[100];
char str[100];

void init(int a[]) {
    scanf("%s", str);
    a[0] = strlen(str);
    for (int i = 1; i <= a[0]; i++) a[i] = str[a[0] - i] - '0';
    return;
}

void print(int a[]) {
    if (a[0] == 0) {
        cout << 0 << endl;
        return;
    }
    for (int i = a[0]; i > 0; i--) cout << a[i];
    cout << endl;
    return;
}

void numcpy(int p[], int q[], int det) {
    for (int i = 1; i <= p[0]; i++) q[i + det - 1] = p[i];
    q[0] = p[0] + det - 1;

    return;
}

int compare(int a[], int b[]) {
    if (a[0] > b[0]) return 1;
    if (a[0] < b[0]) return -1;
    for (int i = a[0]; i > 0; i--) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
    }
    return 0;
}

void gaojian(int a[], int b[]) {
    if (compare(a, b) == 0) {
        a[0] = 0;
        return;
    }
    for (int i = 1; i <= a[0]; i++) {
        if (a[i] < b[i]) {
            a[i + 1]--;
            a[i] += 10;
        }
        a[i] -= b[i];
    }
    while (a[0] > 0 && a[a[0]] == 0) a[0]--;
    
    return;
}

void gaochu(int a[], int b[], int c[]) {
    c[0] = a[0] - b[0] + 1;
    int tmp[100];
    for (int i = c[0]; i > 0; i--) {
        memset(tmp, 0, sizeof(tmp));
        numcpy(b, tmp, i);
        while (compare(a, tmp) >= 0) {
            c[i]++;
            gaojian(a, tmp);
        }
    }
    while (c[0] > 0 && c[c[0]] == 0) c[0]--;
    
    return;
}

int main() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    
    init(a);
    init(b);
    gaochu(a, b, c);
    print(c);
    print(a);

    return 0;
}