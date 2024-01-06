#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    long long x, y, x1, y1, x2, y2;
    cin >> x >> y;
    long double tot = 0;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        tot += sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }
    
    tot = tot * 2 / 1000 / 20;
    int h = floor(tot);
    cout << h << ':';
    tot = (tot - h) * 60;
    int m = tot;
    if (tot - m >= 0.5) m++;
    else if (m < 10) cout << '0';
    cout << m << endl;
    
    return 0;
}