#include <bits/stdc++.h>

using namespace std;

int n, p, c;
int cow[505];
int hd[808], nx[1500], to[1500], w[1500], tot;
int x, y, z;
bool v[808];
int dis[808];

void add(int u, int v, int dis) {
    nx[++tot] = hd[u];
    to[tot] = v;
    w[tot] = dis;
    hd[u] = tot;
}

int main() {
    cin >> n >> p >> c;
    for (int i = 1; i <= n; i++) cin >> cow[i];
    for (int i = 1; i <= c; i++) {
        cin >> x >> y >> z;
        add(x, y, z); add(y, x, z);
    }
    
    int ans = 0x7fffffff >> 1;
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= p; j++) dis[j] = 0x7fffffff >> 1;
        // 可以用循环数组
        int que[10000];
        int front = 0, tail = 1;
        memset(v, 0, sizeof(v));
        que[1] = i;
        v[i] = true;
        dis[i] = 0;
        
        while (front < tail) {
            ++front;
            int cur = que[front];
            v[cur] = false;
            for (int j = hd[cur]; j > 0; j = nx[j]) {
                if (dis[cur] + w[j] < dis[to[j]]) {
                    dis[to[j]] = dis[cur] + w[j];
                    if (!v[j]) {
                        que[++tail] = j;
                        v[j] = true;
                    }
                }
            }
        }
        
        int maxx = 0;
        for (int i = 1; i <= n; i++) maxx += dis[cow[i]];
        if (maxx < ans) ans = maxx;
    }
    
    cout << ans << endl;
    

    return 0;
}