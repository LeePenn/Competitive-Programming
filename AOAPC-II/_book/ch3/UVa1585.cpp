// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 102;
int n;
char s[N];

int main() {
    cin >> n;
    while (n--) {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        int ans = 0, cnt = 0;
        for (int i = 1; i <= len; i++) {
            if (s[i] == 'O') cnt++, ans += cnt;
            else cnt = 0;
        }
        printf("%d\n", ans);
    }
    return 0;
}