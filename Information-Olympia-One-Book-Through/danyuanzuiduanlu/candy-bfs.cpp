#include <bits/stdc++.h>

using namespace std;

int n, p, c, m;
int hd[100000], nx[100000], to[100000], tot;
bool v[100000];

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
    
    memset(v, 0, sizeof(v));
    int queue[100000][2];
    int front = 0, tail = 1;
    queue[1][0] = c, queue[1][1] = 1;
    v[1] = true;
    int ans = 1;
    while (front < tail) {
        ++front;
        int cur = queue[front][0], t = queue[front][1];
        for (int i = hd[cur]; i > 0; i = nx[i]) {
            if (!v[to[i]]) {
                queue[++tail][0] = to[i];
                queue[tail][1] = t + 1;
                ans = max(ans, t + 1);
                v[to[i]] = true;
            }
        }
    }
    
    cout << ans + m << endl;

    return 0;
}