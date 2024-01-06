#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    cin >> s;
    if (s.length() % 2 == 0) {
        cout << "No" << endl;
        return 0;
    }
    int l = s.length();
    bool same = true;
    for (int i = 1; i < l - 1; i += 2) {
        if ((s[i] == '#' && s[i + 1] != '#') || (s[i] != '#' && s[i + 1] == '#')) {
            same = false;
            break;
        }
    }
    if (same) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}