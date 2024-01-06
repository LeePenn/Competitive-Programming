#include <bits/stdc++.h>

using namespace std;

int n, k, q[200005][2];
int hd, tail;
bool v[200005];

void work() {
    hd = 0, tail = 1;
    memset(v, 0, sizeof(v));
    q[1][0] = n, q[1][1] = 0;
    v[n] = 1;
    do {
        hd++;
        int cur = q[hd][0];
        int nx = cur + 1;
        if (!v[nx]) {
            tail++;
            q[tail][0] = nx, q[tail][1] = q[hd][1] + 1;
            v[nx] = 1;
            if (nx == k) {
                printf("%d\n", q[tail][1]);
                return;
            }
        }
        
        nx = cur - 1;
        if (nx > 0 && !v[nx]) {
            tail++;
            q[tail][0] = nx, q[tail][1] = q[hd][1] + 1;
            v[nx] = 1;
            if (nx == k) {
                printf("%d\n", q[tail][1]);
                return;
            }
        }
        
        nx = 2 * cur;
        if (nx <= 2 * k && !v[nx]) {
            tail++;
            q[tail][0] = nx, q[tail][1] = q[hd][1] + 1;
            v[nx] = 1;
            if (nx == k) {
                printf("%d\n", q[tail][1]);
                return;
            }
        }
        
    } while (hd < tail);
}

int main() {
    cin >> n >> k;
    work();

    return 0;
}