// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 101;
string a, b;

int main() {
    int H[3 * N];
    while (cin >> a >> b) {
        int l1 = a.size(), l2 = b.size();
        memset(H, 0, sizeof(H));
        for (int i = 0; i < l1; i++) {
            H[i + N] = a[i] - '0';
        }
        int ans = l1 + l2;
        for (int b2 = N - l2; b2 <= N + l1; b2++) {
            bool ok = true;
            for (int i = 0; i < l2; i++) {
                if (b[i] - '0' + H[i + b2] > 3) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans = min(ans, max(b2 + l2, N + l1) - min(b2, N));
        }
        printf("%d\n", ans);
    }
    
    return 0;
}