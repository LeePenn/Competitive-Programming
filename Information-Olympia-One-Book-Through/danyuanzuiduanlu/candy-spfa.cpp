#include <bits/stdc++.h>

using namespace std;

int n, p, c, m;
int tot, hd[100000], nx[100000], to[100000];
int d[100000];

void add(int u, int v) {
    nx[++tot] = hd[u];
    to[tot] = v;
    hd[u] = tot;
}

int main() {
    cin >> n >> p >> c >> m;
    for (int i = 1; i <= p; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y); add(y, x);
    }
    
    int queue[100000];
    bool v[100000];
    memset(v, 0, sizeof(v));
    int front = 0, tail = 1;
    queue[1] = c;
    v[c] = true;
    for (int i = 1; i <= n; i++) d[i] = 0x7fffffff >> 1;
    d[c] = 1;
    while (front < tail) {
        ++front;
        int cur = queue[front];
        for (int i = hd[cur]; i > 0; i = nx[i]) {
            int t = to[i];
            if (d[t] > d[cur] + 1) {
                d[t] = d[cur] + 1;
                if (!v[t]) {
                    queue[++tail] = t;
                    v[t] = true;
                }
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, d[i]);
    cout << ans + m << endl;

    return 0;
}