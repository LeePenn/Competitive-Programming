#include <bits/stdc++.h>

using namespace std;

int n, a[10000];

void qsort(int l, int r) {
    int mid = a[(l + r) / 2];
    int i = l, j = r;
    while (i <= j) {
        // <= >= 可能溢出
        while (a[i] < mid) i++;
        while (a[j] > mid) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++, j--;
        }
    }
    if (j > l) qsort(l, j);
    if (i < r) qsort(i, r);
    
    return;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    qsort(1, n);
    for (int i = 1; i <= n; i++) cout << a[i];
    cout << endl;

    return 0;
}