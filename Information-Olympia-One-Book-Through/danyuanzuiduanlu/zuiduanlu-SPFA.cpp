#include <bits/stdc++.h>

using namespace std;

const int MAX = 0x7fffffff >> 1;
int m, n;
// 初始化很多大数组时，在全局变量初始化，放在main里有栈大小限制，会报segmentation fault错误
int tot, hd[1000000], nx[1000000], to[1000000], c[1000000];
int d[1000000];
bool exist[1000000];

void add(int u, int v, int w) {
    nx[++tot] = hd[u];
    to[tot] = v;
    c[tot] = w;
    hd[u] = tot;
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z); add(y, x, z);
    }

    for (int i = 1; i <= n; i++) d[i] = MAX;
    d[1] = 0;
    int queue[2000000];
    int front = 0, tail = 1;
    queue[1] = 1;
    
    memset(exist, 0, sizeof(exist));
    exist[1] = true;
    while (front < tail) {
        ++front;
        int cur = queue[front];
        exist[cur] = false;
        for (int i = hd[cur]; i > 0; i = nx[i]) {
            if (d[to[i]] > d[cur] + c[i]) {
                d[to[i]] = d[cur] + c[i];
                if (!exist[to[i]]) {
                    queue[++tail] = to[i];
                    exist[to[i]] = true;
                }
            }
        }
    }
    
    cout << d[n] << endl;
    
    return 0;
}