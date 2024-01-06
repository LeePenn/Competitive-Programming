#include <bits/stdc++.h>

using namespace std;

int n, m;

int gcd(int n, int m) {

    return m == 0 ? n : gcd(m, n % m);
}
int main() {

    cin >> n >> m;

    cout << gcd(n, m) << endl;

    return 0;
}