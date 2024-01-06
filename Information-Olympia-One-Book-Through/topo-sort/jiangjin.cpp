#include <bits/stdc++.h>

using namespace std;

int n, m;
int indgr[1000];
int e[1000][1000];


int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        e[b][++e[b][0]] = a;
        indgr[a]++;
    }
    
    int ans = 0;
    int salary = 100;
    while (n) {
        int t = 0;
        int cur[100];
        for (int j = 1; j <= n; j++) {
            if (indgr[j] == 0) {
                cur[++t] = j;
                indgr[j] = 0x7fffffff >> 1;
            }
        }
        if (t == 0) {
            cout << "Poor Xed" << endl;
            return 0;
        }
        ans += salary * t;
        salary++;
        for (int i = 1; i <= t; i++) {
            for (int j = 1; j <= e[cur[i]][0]; j++) {
                indgr[e[cur[i]][j]]--;
            }
        }
        n -= t;
    }
    cout << ans << endl;
    
    return 0;
}