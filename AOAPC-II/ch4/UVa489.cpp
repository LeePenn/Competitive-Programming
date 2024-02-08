// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 102;
char a[N], b[N];
int n;

int main() {
    while (scanf("%d", &n) == 1 && n != -1) {
        scanf("%s %s", a, b);
        int cnt[26] = {0}, ans = 0, miss = 0;
        int len = strlen(a);
        for (int i = 0; i < len; i++) {
            cnt[a[i] - 'a']++;
        }
        len = strlen(b);
        bool win = 0;
        for (int i = 0; i < len; i++) {
            if (cnt[b[i] - 'a']) {
                ans += cnt[b[i] - 'a'];
                cnt[b[i] - 'a'] = 0;
            } else {
                miss++;
            }
            if (miss == 7) break;
            if (ans == strlen(a)) {
                win = 1;
                break;
            }
        }
        printf("Round %d\n", n);
        win ? puts("You win.") : (miss < 7 ? puts("You chickened out.") : puts("You lose.")) ;
    }
    
    return 0;
}