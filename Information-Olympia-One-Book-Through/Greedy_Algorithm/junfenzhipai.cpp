#include <bits/stdc++.h>

using namespace std;

int a[1000], n, avg, ans;

int main() {    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        avg += a[i];
    }
    
    avg /= n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        a[i] -= avg;
        sum += a[i];
        if (sum != 0) ans++;
    }
    
    cout << ans << endl;
    

    return 0;
}