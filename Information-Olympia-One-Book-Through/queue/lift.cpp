#include <bits/stdc++.h>

using namespace std;

int n, a, b, c[200], d[200];

void work() {
    for (int i = 1; i <= n; i++) d[i] = -1;
    int q[2000][2];
    int front = 1, rear = 2;
    q[1][0] = a, q[1][1] = 0;
    d[a] = 0;
    while (front < rear) {
        int p = q[front][0], t = q[front][1];
        front++;
        for (int i = -1; i <= 1; i+=2) {
            int np = c[p] * i + p;
            if (np >= 1 && np <= n && (d[np] == -1 || d[np] > t + 1)) {
                q[rear][0] = np, q[rear][1] = t + 1;
                d[np] = t + 1;
                rear++;
            }
        }
    }
}

int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) cin >> c[i];
    work();
    cout << d[b] << endl;

    return 0;
}