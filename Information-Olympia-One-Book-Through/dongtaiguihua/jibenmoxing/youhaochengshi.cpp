#include <bits/stdc++.h>

using namespace std;

int n, f[10000];
struct youhao {
    int x, y;
}a[10000];

bool cmp(const youhao &p, const youhao &q) {
    return p.x < q.x;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    
    sort(a + 1, a + n + 1, cmp);
    f[1] = 1;
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i].y > a[j].y) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    
    return 0;
}