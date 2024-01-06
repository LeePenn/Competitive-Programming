#include <bits/stdc++.h>

using namespace std;

int n, a[1000][1000];
int b[1000];

void dfs(int son, int pa) {
    if (b[son] == pa) return;
    
    b[son] = pa;
    for (int i = 1; i <= a[son][0]; i++) dfs(a[son][i], pa);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        while (cin >> x) {
            if (x == 0) break;
            a[i][++a[i][0]] = x;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) {
            dfs(i, i);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) if (b[i] == i) ans++;
    cout << ans << endl;

    return 0;
}