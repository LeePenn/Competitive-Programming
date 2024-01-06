#include <bits/stdc++.h>

using namespace std;

int n;
string dic[50000], b;
int indgr[27];
int ch[27];
int e[27][50000];
int exis[27];
int stk[27], top;

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> dic[i];
    
    cin >> b;
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < dic[i].length(); j++) {
            if (exis[dic[i][j] - 96] == 0) {
                exis[dic[i][j] - 96] = 1;
                tot++;
            }
        }
    }
    for (int i = 0; i < b.length(); i++) {
        if (exis[b[i] - 96] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = 0; k < min(dic[i].length(), dic[j].length()); k++) {
                if (dic[i][k] != dic[j][k]) {
                    int num1 = dic[i][k] - 96, num2 = dic[j][k] - 96;
                    indgr[num2]++;
                    e[num1][++e[num1][0]] = num2;
                    break;
                }
            }
        }
    }
    
    for (int i = 1; i <= 26; i++) {
        if (indgr[i] == 0 && exis[i] == 1) {
            stk[++top] = i;
        }
    }
    
    
    int t = 1;
    int ans[27];
    memset(ans, 0, sizeof(ans));
    while (t <= tot) {
        int cur = stk[t];
        ans[cur] = t;
        t++;
        int tot_edge = e[cur][0];
        for (int i = 1; i <= tot_edge; i++) {
            indgr[e[cur][i]]--;
            if (indgr[e[cur][i]] == 0) {
                stk[++top] = e[cur][i];
            }
        }
    }
    for (int i = 0; i < b.length(); i++) {
        if (ans[b[i] - 96] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    for (int i = 0; i < b.length(); i++) {
        cout  << (char)(ans[b[i] - 96] + 96);
    }
    cout << endl;

    return 0;
}