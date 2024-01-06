#include <bits/stdc++.h>

using namespace std;

int main() {

    long long x;

    cin >> x;

    if (x < 0) {
        x = -x;
        cout << '-';
    }
    while (x > 0 && x % 10 == 0) {
        x /= 10;
    }

    while (x > 0) {
        long long t = x % 10;
        cout << t;
        x /= 10;
    }
    cout << endl;

    return 0;
}