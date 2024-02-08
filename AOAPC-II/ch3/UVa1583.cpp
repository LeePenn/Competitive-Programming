// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 100002;
int n, ans[N];

int main() {
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i < N; i++) {
        int x = i, y = i;
        while (x) {
            y += x % 10;
            x /= 10;
        }
        if (!ans[y] || i < ans[y]) ans[y] = i;
    }
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        printf("%d\n", ans[n]);
    }
    return 0;
}