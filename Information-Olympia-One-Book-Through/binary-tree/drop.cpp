#include <bits/stdc++.h>

using namespace std;

int d, n;

int main() {
    cin >> d >> n;
    d--;
    int ans = 1;
    while (d--) {
        n >>= 1;
        if (n & 1) {
            ans <<= 1;
            ans++;
        } else {
            ans <<= 1;
        }
    }
    cout << ans << endl;
    

    return 0;
}