#include <bits/stdc++.h>

using namespace std;

int tot, f[50000];
string pa, son, qa, b[50000];

int get_num(string s) {
    for (int i = 1; i <= tot; i++) {
        if (b[i] == s) return i;
    }
    b[++tot] = s;
    return tot;
}

int find(int x) {
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void uni(string x, string y) {
    int numx = get_num(x), numy = get_num(y);
    int fx = find(numx), fy = find(numy);
    f[fy] = fx;
}

int main() {
    ios::sync_with_stdio(false);
    for (int i = 1; i <= 50000; i++) f[i] = i;
    while (1) {
        switch (getchar()) {
            case '#': {
                cin >> pa;
                break;
            }
            case '+': {
                cin >> son;
                uni(pa, son);
                break;
            }
            case '?': {
                cin >> qa;
                int num = get_num(qa);
                int father = find(num);
                cout << qa << ' ' << b[father] << endl;
                break;
            }
            case '$':
                return 0;
                break;
        }
    }
    return 0;
}