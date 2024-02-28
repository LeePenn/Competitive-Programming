// Joker
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, sp, sq;

int main() {
    while (scanf("%lld %lld %lld", &n, &sp, &sq) == 3) {
        auto f = [](ll x, int a, int b) {
            return (x + (x << a)) >> b;
        };
        ll k = LLONG_MAX;
        int a = 64, b = 64;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                if (f(sp, i, j) < sq) continue;
                ll K = f(sp * (n - 1), i, j) + sq;
                if (K < k) {
                    k = K, a = i, b = j;
                }
            }
        }
        printf("%lld %d %d\n", k, a, b);
    }
    
    return 0;
}