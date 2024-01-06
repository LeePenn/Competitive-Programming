#include <bits/stdc++.h>

using namespace std;

char s[100], ans[100];

int up(int idx) {
    if (idx == -1) return -1;
    if (ans[idx] == '$') return idx;
    return up(idx - 1);
}

int main() {
    while (scanf("%s", s) == 1) {
        printf("%s\n", s);
        memset(ans, ' ', sizeof(ans));
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') ans[i] = '$';
            else if (s[i] == ')') {
                int d = up(i - 1);
                if (d == -1) {
                    ans[i] = '?';
                } else {
                    ans[d] = ' ';
                }
            }
        }
        printf("%s\n", ans);
    }


    return 0;
}