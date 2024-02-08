// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 102;
int n, t, len;
string s;

int get_min() {
    int k;
    int i = 0, j = 1;
    while (i < len && j < len) {
        for (k = 0; k < len; k++) {
            if (s[i + k] != s[j + k]) break;
        }
        if (s[i + k] > s[j + k]) {
            i = i + k + 1;
            if (i == j) i++;
        } else if (s[j + k] > s[i + k]) {
            j = j + k + 1;
            if (j == i) j++;
        }
    }
    return min(i, j);
}

int main() {
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        len = str.size();
        s = str + str;
        int st = get_min();
        for (int i = st; i < st + len; i++) printf("%c", s[i]);
        puts("");
    }
    return 0;
}