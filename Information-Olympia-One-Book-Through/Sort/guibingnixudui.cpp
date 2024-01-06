#include <bits/stdc++.h>

using namespace std;

int a[10000], n, ans;

void msort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    msort(l, mid);
    msort(mid + 1, r);
    int b[10000], bi = l;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            b[bi] = a[i];
            i++, bi++;
        } else {
            b[bi] = a[j];
            ans += mid - i + 1;
            j++, bi++;
        }
    }
    while (i <= mid) {
        b[bi] = a[i];
        i++, bi++;
    }
    while (j <= r) {
        b[bi] = a[j];
        j++, bi++;
    }
    for (i = l; i <= r; i++) a[i] = b[i];


    return;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    msort(1, n);
    cout << ans << endl;


    return 0;
}