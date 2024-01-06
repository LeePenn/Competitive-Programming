#include <bits/stdc++.h>

using namespace std;

int n, m;
int q[1000];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) q[i] = i + 1;
    q[n] = 1;
    int p = n;
    while (n--) {
        int k = 1;
        // at last, u need to change pre-point, so k < m, then p is pre-point, out q[p]
        while (k < m) {
            p = q[p];
            k++;
        }
        printf("%d ", q[p]);
        q[p] = q[q[p]];
    }
    printf("\n");
    return 0;
}