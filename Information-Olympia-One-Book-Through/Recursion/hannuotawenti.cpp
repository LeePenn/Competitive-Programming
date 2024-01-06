#include <bits/stdc++.h>

using namespace std;

int n;
char x, y, z;

void hano(int n, char a, char b, char c) {
    if (n == 0) return;
    
    hano(n - 1, a, c, b);
    printf("%c->%d->%c\n", a, n, b);
    hano(n - 1, c, b, a);

    return;
}

int main() {
    scanf("%d %c %c %c", &n, &x, &y, &z);
    hano(n, x, y, z);

    return 0;
}