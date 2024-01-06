#include <bits/stdc++.h>

using namespace std;

int m, n, d[505], g[505][505];
bool v[505];
string s;

void build_edge() {
    int len = s.length();
    int a[505];
    int tot = 0;
    int i;
    for (i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            int num = 0;
            while (i < s.length() && isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
                i++;
            }
            a[++tot] = num;
        }
    }
    for (int i = 1; i <= tot; i++) {
        for (int j = i + 1; j <= tot; j++) {
            g[a[i]][a[j]] = 1;
        }
    }
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) 
            g[i][j] = g[j][i] = 0x7fffffff >> 1;
    }
    // "eat" \n line
    getline(cin, s);
    for (int i = 1; i <= m; i++) {
        getline(cin, s);
        build_edge();
    }
    
    for (int i = 1; i <= n; i++) d[i] = 0x7fffffff >> 1;
    memset(v, 0, sizeof(v));
    d[1] = 0;
    v[1] = true;
    for (int i = 1; i <= n; i++) {
        if (!v[i] && d[i] > d[1] + g[1][i]) {
            d[i] = d[1] + g[1][i];
        }
    }
    for (int i = 1; i < n; i++) {
        int k = 0;
        int minx = 0x7fffffff >> 1;
        for (int j = 1; j <= n; j++) {
            if (!v[j] && d[j] < minx) {
                k = j;
                minx = d[j];
            }
        }
        if (k == 0 || k == n) break;
        v[k] = true;
        for (int j = 1; j <= n; j++) {
            if (!v[j] && d[j] > d[k] + g[k][j]) {
                d[j] = d[k] + g[k][j];
            }
        }
    }
    
    if (d[n] == (0x7fffffff >> 1)) cout << "NO" << endl;
    else cout << d[n] - 1 << endl;

    return 0;
}