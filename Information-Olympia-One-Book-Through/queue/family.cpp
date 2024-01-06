#include <bits/stdc++.h>

using namespace std;

int n, k, a[1000], b[1000];
int ans;
bool v[1000];

void work(int x) {
    int cnt = 1;
    int q[1000];
    int front = 1, rear = 2;
    v[x] = true;
    q[1] = x;
    while (front < rear) {
        int cur = q[front];
        front++;
        for (int i = 1; i <= k; i++) {
            if (a[i] == cur || b[i] == cur) {
                int nx = a[i] + b[i] - cur;
                if (!v[nx]) {
                    q[rear] = nx;
                    rear++;
                    cnt++;
                    v[nx] = true;
                }
            }
        }
    }
    ans = max(ans, cnt);
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) scanf("%d %d", &a[i], &b[i]);
    
    memset(v, 0, sizeof(v));
    ans = 0;
    int num = 0;
    for (int i = 1; i <= n; i++) if (!v[i]) {work(i); num++;}
    
    printf("%d %d\n", num, ans);

    return 0;
}
