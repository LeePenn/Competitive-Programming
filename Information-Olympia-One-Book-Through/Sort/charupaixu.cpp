#include <bits/stdc++.h>

using namespace std;

int a[10000], n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        int j;
        for (j = i - 1; j > 0; j--) {
            if (a[j] < a[i]) break;
        }
        if (j != i - 1) {
            int temp = a[i];
            for (int k = i - 1; k > j; k--) {
                a[k + 1] = a[k];
            }
            a[j + 1] = temp;
        }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;


    return 0;
}