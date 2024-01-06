#include <bits/stdc++.h>

using namespace std;

int n, k, a[20], b[20];
bool v[100000];
int ans;

void work() {
    int q[100000];
    int front = 1, rear = 2;
    q[1] = n;
    while (front < rear) {
        int cur = q[front];
        front++;
        int x = cur, mod = 1;
        while (cur > 0) {
            int temp = cur % 10;
            for (int i = 1; i <= k; i++) {
                if (a[i] != temp) continue;
                int nx = x + (b[i] - temp) * mod;
                if (!v[nx]) {
                    q[rear] = nx;
                    ans++;
                    rear++;
                    v[nx] = true;
                }
            }
            cur /= 10;
            mod *= 10;
        }
    }
}   

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    ans = 1;
    v[n] = true;
    work();
    printf("%d\n", ans);

    return 0;
}