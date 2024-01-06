#include <bits/stdc++.h>

using namespace std;

int a[10000], n;

void qsort(int l, int r) {
    int i = l, j = r;
    int mid = a[(l + r) / 2];
    int temp;
    do {
        while (a[i] < mid) i++;
        while (a[j] > mid) j--;
        if (i <= j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        i++, j--;
    } while (i <= j);
    if (l < j) qsort(l, j);
    if (r > i) qsort(i, r);
    
    return;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    qsort(1, n);
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;


    return 0;
}