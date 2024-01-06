#include <bits/stdc++.h>

using namespace std;

string s, s1;
int a, b, c;

int main() {
    int n;
    cin >> s;
    cin >> n;
    s1 = s;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        int len = b - a + 1;
        c %= len;
        for (int j = a; j <= b; j++) {
            s1[j] = s[j];
        }
        for (int j = a; j <= b; j++) {
            if (j + c > b) s[j] = s1[j + c - len];
            else s[j] = s1[j + c];
        }
    }
    cout << s;

    return 0;
}