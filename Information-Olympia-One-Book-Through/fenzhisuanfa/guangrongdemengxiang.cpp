#include <bits/stdc++.h>

using namespace std;

int n, a[10000], ans;

int msort(int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    int cnt = msort(l, mid) + msort(mid + 1, r);
    int b[10000];
    int bi = l;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            b[bi++] = a[i++];
        } else {
            cnt += mid - i + 1;
            b[bi++] = a[j++];
        }
    }
    while (i <= mid) b[bi++] = a[i++];
    while (j <= r) b[bi++] = a[j++];
    for (int k = l; k <= r; k++) a[k] = b[k];
    return cnt;

}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    printf("%d\n", msort(1, n));

    return 0;
}   