#include <bits/stdc++.h>

using namespace std;

int a[1000], b[1000], x, y, z;

int main() {
    scanf("%d%d%d", &x, &y, &z);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= x; i++) {
        a[i] = 1;
        b[i] = 0;
    }
    for (int i = x + 1; i <= z + 1; i++) {
        b[i] = a[i - x] * y;
        a[i] = a[i - 1] + b[i - 2];
    }
    cout << a[z + 1] << endl;

    return 0;
}