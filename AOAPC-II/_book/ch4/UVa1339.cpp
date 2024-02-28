// Joker
#include <bits/stdc++.h>
using namespace std;
char s1[103], s2[103];
int c1[26], c2[26];

int main() {
    while (scanf("%s %s", s1, s2) == 2) {
        int l = strlen(s1);
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        for (int i = 0; i < l; i++) {
            c1[s1[i] - 'A']++;
            c2[s2[i] - 'A']++;
        }
        sort(c1, c1 + 26);
        sort(c2, c2 + 26);
        bool ok = true;
        for (int i = 0; i < 26; i++) {
            if (c1[i] != c2[i]) {
                ok = false;
            }
        }
        ok ? puts("YES") : puts("NO");
    }
    
    return 0;
}