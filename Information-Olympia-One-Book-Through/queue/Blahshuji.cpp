#include <bits/stdc++.h>

using namespace std;

int x, n;
long long q[1000000];
int p2, p3;

int main() {
    while (scanf("%d %d", &x, &n) == 2) {
        q[1] = x;
        int i = 2;
        int rear = 2;
        p2 = p3 = 1;
        while (i <= n) {
            long long t1 = 2 * q[p2] + 1;
            long long t2 = 3 * q[p3] + 1;
            if (t1 <= t2) p2++;
            else p3++;
            long long t = min(t1, t2);
            if (t == q[rear - 1]) {
                continue;
            }
            q[rear++] = t;
            i++;
        }
        printf("%lld\n", q[n]);
    }
}