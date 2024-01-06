#include <bits/stdc++.h>

using namespace std;

string s1, s2, ss1, ss2, k;
int l1, l2, ans = -100000, f = -1;

int main() {
    cin >> s1 >> s2;
    ss1 = s1 + s1;
    ss2 = s2 + s2;
    l1 = ss1.size(), l2 = ss2.size();
    if (l1 > l2) {
        swap(ss1, ss2);
        l1 = ss1.size();
        l2 = ss2.size();
    }
    for (int i = 0; i < l1 / 2; i++) {
        for (int j = 1; j <= l1 / 2; j++) {
            f = ss2.find(ss1.substr(i, j));
            if (f != -1) {
                if (j > ans) {
                    ans = j;
                }
            }
        }
    }
    cout << ans;

    return 0;
}