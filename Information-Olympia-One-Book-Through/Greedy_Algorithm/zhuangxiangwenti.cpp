#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, e, f, n;
int aa[] = {0, 5, 3, 1};

int main() {
    while (1) {
        cin >> a >> b >> c >> d >> e >> f;
        if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0) {
            break;
        }
        
        n = f + e + d + (c + 3) / 4;
        int x22 = 5 * d + aa[c % 4];
        if (x22 < b) {
            n += (b - x22 + 8) / 9;
        }
        int x11 = 36 * n - 36 * f - 25 * e - 16 * d - 9 * c - 4 * b;
        if (x11 < a) {
            n += (a - x11 + 35) / 36;
        }
        cout << n << endl;
    }

    return 0;
}