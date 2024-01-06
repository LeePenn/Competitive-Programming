#include <bits/stdc++.h>

using namespace std;

int a[10000], n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++) {
        bool ok = true;
        for (int j = 1; j <= n - i; j++){
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                ok = false;
            }
        }
        if (ok) break;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;


    return 0;
}