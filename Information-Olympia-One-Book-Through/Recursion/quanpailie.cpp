#include <bits/stdc++.h>

using namespace std;

bool b[100];
char s[100], ans[100];
int len;

void dfs(int cnt) {
    if (cnt == len) {
        printf("%s\n", ans);
        return;
    }
    for (int i = 0; i < len; i++) {
        if (!b[i]) {
            ans[cnt] = s[i];
            b[i] = true;
            dfs(cnt + 1);
            b[i] = false;
        }
    }


    return;
}

int main() {
    scanf("%s", s);
    len = strlen(s);
    dfs(0);


    return 0;
}