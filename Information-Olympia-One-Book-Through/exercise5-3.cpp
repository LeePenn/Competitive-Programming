#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    getline(cin, s);
    int diff = 'a' - 'A';
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += diff;
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= diff;
        }
    }
    cout << s << endl;


    return 0;
}