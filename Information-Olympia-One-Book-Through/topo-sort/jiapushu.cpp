#include <bits/stdc++.h>

using namespace std;

int n, indgr[1000];
int stk[1000], top;
int tot, hd[2000], nx[2000], to[2000];

void add(int x, int y) {
    nx[++tot] = hd[x];
    to[tot] = y;
    hd[x] = tot;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++) {
        while (cin >> x) {
            if (x == 0) break;
            indgr[x]++;
            add(i, x);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (indgr[i] == 0) stk[++top] = i;
    }
    
    while (top > 0) {
        int cur = stk[top]; top--;
        cout << cur << ' ';
        for (int i = hd[cur]; i > 0; i = nx[i]) {
            indgr[to[i]]--;
            if (indgr[to[i]] == 0) stk[++top] = to[i];
        }
    }
    cout << endl;
    return 0;
}