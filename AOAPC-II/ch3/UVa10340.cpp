// Joker
#include <bits/stdc++.h>
using namespace std;
string s, t;

int main() {
    while (cin >> s >> t) {
        int l1 = s.size(), l2 = t.size();
        int i = 0, j = 0;
        while (i < l1 && j < l2) {
            if (s[i] == t[j]) {
                i++, j++;
            } else {
                j++;
            }
        }
        i == l1 ? puts("Yes") : puts("No");
    }
    return 0;
}