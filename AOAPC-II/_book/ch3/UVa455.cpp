// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 256;
char s[N];
int n, Next[N];

void calc_next() {
   memset(Next, 0, sizeof(Next));
   int len = strlen(s + 1);
   for (int i = 2, j = 0; i <= len; i++) {
       while (j && s[i] != s[j + 1]) j = Next[j];
       if (s[i] == s[j + 1]) j++;
       Next[i] = j;
   }
}

int main() {
    cin >> n;
    bool first = true;
    //cout << n << endl;
    //cout << "asdf" << endl;
    while (n--) {
        if (first) first = false;
        else puts("");
        scanf("%s", s + 1);
        calc_next();
        int len = strlen(s + 1);
        if (len % (len - Next[len]) == 0) printf("%d\n", len - Next[len]);
        else printf("%d\n", len);
    }
    return 0;
}