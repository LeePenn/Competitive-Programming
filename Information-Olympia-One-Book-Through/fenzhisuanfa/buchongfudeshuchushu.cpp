#include <bits/stdc++.h>

using namespace std;

int n, a[100000];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i + 1]) cout << a[i] << ' ';
    }
    cout << a[n] << endl;

    return 0;
}