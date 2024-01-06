#include <bits/stdc++.h>

using namespace std;

int n, x;
string s;
map<int, int> a;
map<int, bool> b;

int main() {
    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "add") {
            cin >> x;
            a[x]++;
            b[x] = true;
            printf("%d\n", a[x]);
        }
        if (s == "del") {
            cin >> x;
            printf("%d\n", a[x]);
            a[x] = 0;
        }
        if (s == "ask") {
            cin >> x;
            printf("%d %d\n", b[x], a[x]);
        }
    }

    return 0;
}