#include <bits/stdc++.h>

using namespace std;

int a[10000], b[105], n;

int main() {
    scanf("%d", &n);
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]); 
        b[a[i]]++;
    }
    for (int i = 0; i <= 104; i++) {
        while (b[i] > 0) {
            cout << i << ' ';
            b[i]--;
        }
    }
    cout << endl;

    return 0;
}