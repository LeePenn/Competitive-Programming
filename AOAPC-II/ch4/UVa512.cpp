// Joker
#include <bits/stdc++.h>
using namespace std;
const int BIG = 10000;
int r, c, op;
int change[100];
char cmd[10];
int a[100][100], a1[100][100], ans[100][100];

void copy(char type, int p, int q) {
    if (type == 'R') {
        for (int i = 1; i <= c; i++) {
            a[p][i] = a1[q][i];
        }
    } else {
        for (int i = 1; i <= r; i++) {
            a[i][p] = a1[i][q];
        }
    }
}

void del(char type) {
    memcpy(a1, a, sizeof(a1));
    int cnt = type == 'R' ? r : c;
    int cnt1 = 0;
    for (int i = 1; i <= cnt; i++) {
        if (!change[i]) copy(type, ++cnt1, i);
    }
    if (type == 'R') r = cnt1;
    else c = cnt1;
}

void insert(char type) {
    memcpy(a1, a, sizeof(a1));
    int cnt = type == 'R' ? r : c;
    int cnt1 = 0;
    for (int i = 1; i <= cnt; i++) {
        if (change[i]) copy(type, ++cnt1, 0);
        copy(type, ++cnt1, i);
    }
    if (type == 'R') r = cnt1;
    else c = cnt1;
}

int main() {
    int id = 0;
    while (scanf("%d %d %d", &r, &c, &op) == 3 && r) {
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) a[i][j] = i * BIG + j;
        }
        
        for (int i = 1; i <= op; i++) {
            scanf("%s", cmd);
            if (cmd[0] == 'E') {
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                int t = a[x1][y1];
                a[x1][y1] = a[x2][y2];
                a[x2][y2] = t;
            } else {
                memset(change, 0, sizeof(change));
                int n;
                scanf("%d", &n);
                for (int j = 0; j < n; j++) {
                    int x; 
                    scanf("%d", &x);
                    change[x] = 1;
                }
                if (cmd[0] == 'D') del(cmd[1]);
                else insert(cmd[1]);
            }
        }
        if (id > 0) printf("\n");
        printf("Spreadsheet #%d\n", ++id);
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                ans[a[i][j] / BIG][a[i][j] % BIG] = i * BIG + j;
            }
        }
        int k;
        scanf("%d", &k);
        for (int i = 1; i <= k; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("Cell data in (%d,%d) ", x, y);
            if (!ans[x][y]) printf("GONE\n");
            else printf("moved to (%d,%d)\n", ans[x][y] / BIG, ans[x][y] % BIG);
        }
    }
    
    return 0;
}