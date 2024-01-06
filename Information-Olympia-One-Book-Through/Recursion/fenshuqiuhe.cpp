#include <bits/stdc++.h>

using namespace std;

int t, a, b, c, d;

int gcd(int x, int y) {
    if (x % y == 0) return y;
    return gcd(y, x % y);
}

void calc() {
    scanf("%d/%d", &c, &d);
    a *= d, c *= b;
    b *= d, d = b;
    a += c;
    int g = gcd(a, b);
    a /= g, b /= g;

    return;
}

int main() {
    scanf("%d", &t);
    scanf("%d/%d", &a, &b);
    t--;
    while (t--) {
        calc();
    }
    int g = gcd(a, b);
    a /= g, b /= g;
    printf("%d/%d\n", a, b);
    


    return 0;
}