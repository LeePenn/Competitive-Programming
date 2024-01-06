#include <bits/stdc++.h>

using namespace std;

int b, p, k;

int work(int x) {
    if (x == 1) return b % k;
    int tmp = work(x / 2) % k;
    tmp = (tmp * tmp) % k;
    if (x % 2 == 1) tmp = (tmp * b) % k;
    
    return tmp;
}

int main() {
    cin >> b >> p >> k;
    
    b %= k;
    printf("%d^%d mod %d=%d\n", b, p, k, work(p));

    return 0;
}