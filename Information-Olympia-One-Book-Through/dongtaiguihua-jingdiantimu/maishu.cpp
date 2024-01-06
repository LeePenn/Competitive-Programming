#include <bits/stdc++.h>

using namespace std;

int n, f[1005];
const int a[5] = {0, 10, 20, 50, 100};

int main() {
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= 4; i++) {
        for (int j = a[i]; j <= n; j++) {
            f[j] += f[j - a[i]];
        }    
    }
    cout << f[n] << endl;

    return 0;
}