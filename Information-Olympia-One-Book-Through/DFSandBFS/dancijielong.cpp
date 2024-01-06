#include <bits/stdc++.h>

using namespace std;

int n, ans, v[101];
string s[101], ss;

bool can(string x, string y, int k) {
    int len = x.length();
    for (int i = 0; i < k; i++) {
        if (x[len - k + i] != y[i]) return false;
    }
    return true;
}

void cp(string &x, string y, int k) {
    for (int i = k; i < y.length(); i++) x += y[i];
    return;
}

void work(string ss) {
    int len = ss.length();
    ans = max(ans, len);
    for (int i = 1; i <= n; i++) {
        if (v[i] >= 2) continue;
        for (int j = 1; j <= s[i].length(); j++) {
            if (can(ss, s[i], j)) {
                string t = ss;
                cp(t, s[i], j);
                if (t == ss) continue;
                v[i]++;
                work(t);
                v[i]--;
            }
        }
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    cin >> ss;
    work(ss);
    printf("%d\n", ans);

    return 0;
}