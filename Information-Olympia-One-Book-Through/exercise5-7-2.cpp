#include <bits/stdc++.h>

using namespace std;

string s, a, b;

int main() {
    getline(cin ,s); s = " " + s + " ";
    getline(cin ,a); a = " " + a + " ";
    getline(cin ,b); b = " " + b + " ";

    int len = a.length(), pos = s.find(a, 0);
    while (string::npos != pos) {
        s.replace(pos, len, b);
        pos = s.find(a, pos + 1);
    }
    cout << s.substr(1, s.length()) << endl;

    return 0;
}