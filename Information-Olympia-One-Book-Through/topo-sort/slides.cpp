#include <bits/stdc++.h>

using namespace std;

int n;
int pos[27][4];
int num[27][2];
int indgr[27];
int inmap[27][27];
int numinmap[27][27];
int stk[27], top;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pos[i][0] >> pos[i][1] >> pos[i][2] >> pos[i][3];
    }
    for (int i = 1; i <= n; i++) {
        cin >> num[i][0] >> num[i][1];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (num[j][0] >= pos[i][0] && num[j][0] <= pos[i][1] 
            && num[j][1] >= pos[i][2] && num[j][1] <= pos[i][3]) {
                indgr[j]++;
                inmap[i][++inmap[i][0]] = j;
                numinmap[i][j] = 1;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (indgr[i] == 1) {
            stk[++top] = i;
        }
    }
    
    int k = n;
    int ans[27];
    while (k--) {
        if (top == 0) {
            cout << "None" << endl;
            return 0;
        }
        
        int cur = stk[top]; top--;
        indgr[cur]--;
        int temp = 0;
        for (int i = 1; i <= n; i++) {
            if (numinmap[i][cur] == 1) {
                temp = i;
                ans[i] = cur;
                break;
            }
        }
        
        for (int i = 1; i <= inmap[temp][0]; i++) {
            int cur_num = inmap[temp][i];
            numinmap[temp][cur_num] = 0;
            indgr[cur_num]--;
            if (indgr[cur_num] == 1) {
                stk[++top] = cur_num;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) printf("%c %d\n", char(i + 64), ans[i]);

    return 0;
}