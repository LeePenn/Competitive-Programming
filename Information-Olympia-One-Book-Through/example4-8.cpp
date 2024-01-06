#include <bits/stdc++.h>

#define INF 10000000

using namespace std;

int main() {
    int mi = INF, mx = -INF, x, n = 0;
    double avg = 0.0;

    while (scanf("%d", &x) == 1) {
        if (x > mx) {
            mx = x;
        }
        if (x < mi) {
            mi = x;
        }
        avg += x;
        n++;
    }
    avg /= n;

    printf("%d %d %.3lf\n", mi, mx, avg);

    return 0;
}   