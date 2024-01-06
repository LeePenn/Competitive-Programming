#include <bits/stdc++.h>

using namespace std;

int L, R;
char s[10];

int main() {
    cin >> L >> R;
    if (L > R) swap(L, R);

    int ans = 0;
    for (int i = L; i <= R; i++) {
        sprintf(s, "%d", i);
        int len = strlen(s);
        for (int j = 0; j < len; j++) {
            if ('2' == s[j]) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}