#include <bits/stdc++.h>

using namespace std;

int n, k;
double a[10000];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
       cin >> a[i];
       a[i] *= 100;
    }
    
    int x = 0, y = 100000;
    double ans = 0;
    while (x < y) {
        int mid = (x + y) >> 1;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += a[i] / mid;
        }
        if (cnt >= k) {
            x = mid + 1;
            if (mid > ans) ans = mid;
        } else {
            y = mid - 1;
        }
    }
    printf("%.2lf\n", ans / 100);
    
    

    return 0;
}