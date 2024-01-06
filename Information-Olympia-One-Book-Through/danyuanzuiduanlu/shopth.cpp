#include <bits/stdc++.h>

using namespace std;

const int MAX = 0x7fffffff >> 1;
int n, v0;
int d[100][100];
string s;

int get() {
    cin >> s;
    if (s == "-") return MAX;
    if (s[0] == '-') {
        int num = 0;
        for (int i = 1; i < s.length(); i++) {
            num = num * 10 + s[i] - '0';
        }
        return -num;
    } else {
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            num = num * 10 + s[i] - '0';
        }
        return num;
    }
}

int main() {
    cin >> n >> v0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) 
            d[i][j] = d[j][i] = MAX;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
           d[i][j] = get();
        }
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && j != k && i != k) {
                    if (d[i][j] > d[i][k] + d[k][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (i == v0) continue;
        printf("(%d->%d)=%d\n", v0, i, d[v0][i]);
    }

    return 0;
}