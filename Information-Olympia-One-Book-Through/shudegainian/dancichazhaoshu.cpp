#include <bits/stdc++.h>

using namespace std;

int n;
string a[40000];

int main() {
    n = 0;
    string s;
    while (cin >> s) {
        a[++n] = s;
    }
    sort(a + 1, a + n + 1);
    int ans = a[1].length();
    for (int i = 2; i <= n; i++) {
        int j;
        for (j = 0; j < a[i].length(); j++) {
            if (j == a[i - 1].length() || a[i][j] != a[i - 1][j]) break;
        }
        ans += a[i].length() - j;
    }
    cout << ans + 1 << endl;

    return 0;
}