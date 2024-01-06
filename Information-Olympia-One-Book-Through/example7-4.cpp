#include <bits/stdc++.h>

using namespace std;

// 边信息只包含终点(v)和下一条边的起点(u)
struct edge {
    int v, nxt;
} e[200004];

int n, m, u, v, tot;
// h[u] 以u为head的指向的边
int h[5003], len[5003];

// 头插法
void insert(int u, int v) {
    e[++tot].v = v;
    e[tot].nxt = h[u];
    // 节点u对应的边索引
    h[u] = tot; 
    len[u]++;
}

int main() {

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        insert(u, v);
        insert(v, u);
    }

    for (int i = 1; i <= n; i++) {
        cout << len[i] << ' ';
        for (int j = h[i]; j; j = e[j].nxt) {
            cout << e[j].v << ' ';
        }
        cout << endl;
    }

    return 0;
}