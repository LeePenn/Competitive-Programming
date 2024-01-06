#include <bits/stdc++.h>

using namespace std;

string s1, s2;

char x;

int main() {
    cin >> s1 >> s2;
    if (s1.length() < s2.length()) {
        swap(s1, s2);
    }
    int l = s1.length();
    for (int i = 0; i < l; i++) {
        x = s1[0];
        s1 = s1.substr(1, l);
        s1 += x;
        if (string::npos != s1.find(s2, 0)) {
            cout << "true" << endl;
            return 0;
        }
    }
    cout << "false" << endl;


    return 0;
}