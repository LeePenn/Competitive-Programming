#include <bits/stdc++.h>

using namespace std;

int g[100][100];
int n, m, e;

struct Edge {
    int to, dis;
    int nxt;
};
Edge edge[100];
int head[100], tot;

void graph_v1() {
    memset(g, 0x7f, sizeof(g));
    for (int k = 1; k <= e; k++) {
        int i, j, w;
        cin >> i >> j >> w;
        g[i][j] = w;
        g[j][i] = w;
    }
}

void add_edge(int a, int b, int c) {
    edge[++tot].nxt = head[a];
    edge[tot].to = b;
    edge[tot].dis = c;
    head[a] = tot;
}

void graph_v2() {
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edge(a, b, c);
    }
    for (int i = head[1]; i > 0; i = edge[i].nxt) {
        break;
    }
}

int main() {
    

    return 0;
}