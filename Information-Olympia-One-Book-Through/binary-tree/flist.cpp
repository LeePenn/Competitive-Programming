#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int m[255];

void work(int l, int r) {
    if (l > r) return;
    int p = 0x7fffffff;
    int border = 0;
    for (int i = l; i <= r; i++) {
        if (m[s1[i]] < p) {
            p = m[s1[i]];
            border = i;
        }
    }
    cout << s2[p];
    work(l, border - 1);
    work(border + 1, r);
}

int main() {
    cin >> s1 >> s2;
    int l = s2.length() - 1;
    for (int i = 0; i <= l; i++) {
        m[s2[i]] = i;
    }
    work(0, l);
    cout << endl;


    return 0;
}