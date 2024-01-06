#include <bits/stdc++.h>

using namespace std;

int n, a[1000];

int main() {
    memset(a, 0, sizeof(a));
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    for (int i = 4; i <= 105; i++) {
        a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    }
    while (scanf("%d", &n) == 1 && n) {
        cout << a[n] << endl;
    }
    

    return 0;
}