#include <bits/stdc++.h>

using namespace std;

int n;
string s;

char work(int l, int r) {
    if (l == r) {
        if (s[l] == '0') {
            cout << 'B';
            return 'B';
        } else {
            cout << 'I';
            return 'I';
        }
        
    }
    
    int len = r - l + 1;
    len = len >> 1;
    char lc = work(l, l + len - 1);
    char rc = work(l + len, r);
    if (lc == rc) {
        cout << lc;
        return lc;
    } else {
        cout << 'F';
        return 'F';
    }
}

int main() {
    cin >> n >> s;
    work(0, s.length() - 1);
    cout << endl;


    return 0;
}