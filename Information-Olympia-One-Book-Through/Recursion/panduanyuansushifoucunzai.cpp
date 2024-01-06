#include <bits/stdc++.h>

using namespace std;

long long k, x;
bool found;

void check(long long y) {
    if (y > x) return;
    if (found) return;
    if (y == x || 2 * y + 1 == x || 3 * y + 1 == x) {
        found = true;
        return;
    }
    check(2 * y + 1);
    check(3 * y + 1);

    return;
}

int main() {
    scanf("%lld,%lld", &k, &x);
    found = false;
    check(k);

    if (found) printf("YES\n");
    else printf("NO\n");

    return 0;
}