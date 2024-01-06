#include <bits/stdc++.h>

using namespace std;

int n, t, v;

int main() {
    while (1) {
        cin >> n;
        if (n == 0) break;
        
        int ans = 1000000, s = 0;
        for (int i = 1; i <= n; i++) {
            cin >> v >> t;
            if (t >= 0) {
                double Time = (4500 / (v * 10.0 / 36.0));
                if (Time - (int)Time > 0.0) Time++;
                s = Time + t;
                if (ans > s) ans = s;
            }
        }
        
        cout << ans << endl;
    }
    

    return 0;
}