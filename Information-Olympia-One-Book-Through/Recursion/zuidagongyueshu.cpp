#include <bits/stdc++.h>

using namespace std;

int a, b;

int gcd(int x, int y) {
    if (x % y == 0) return y;

    return gcd(y, x % y);
}

int main() {
    scanf("%d %d", &a, &b);
    
    printf("%d\n", gcd(a, b));


    return 0;
}