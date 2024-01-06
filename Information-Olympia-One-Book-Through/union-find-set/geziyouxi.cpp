#include <bits/stdc++.h>

using namespace std;

int n, m;
struct node {
    int x, y;
}; 
node f[200][200];

node find(node a) {
    if (f[a.x][a.y].x == a.x && f[a.x][a.y].y == a.y) return a;
    f[a.x][a.y] = find(f[a.x][a.y]);
    return f[a.x][a.y];
}

void un(node a, node b) {
    node fa = find(a), fb = find(b);
    f[fb.x][fb.y] = fa;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j].x = i, f[i][j].y = j;
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        if (c == 'D') {
            node fa = find(f[a][b]), fb = find(f[a + 1][b]);
            if (fa.x == fb.x && fa.y == fb.y) {
                ans = i;
                break;
            }
            un(f[a][b], f[a + 1][b]);
        } else if (c == 'R') {
            node fa = find(f[a][b]), fb = find(f[a][b + 1]);
            if (fa.x == fb.x && fa.y == fb.y) {
                ans = i;
                break;
            }
            un(f[a][b], f[a][b + 1]);
        }
    }
    
    if (ans == 0) cout << "draw" << endl;
    else cout << ans << endl;

    return 0;
}