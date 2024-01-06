#include <bits/stdc++.h>

using namespace std;

string s, s1, s2;

int main() {
    getline(cin, s);
    int comma1 = s.find(',', 0);
    int comma2 = s.find(',', comma1 + 1);
    int s1len = comma2 - comma1 - 1;
    s1 = s.substr(comma1 + 1, s1len);
    s2 = s.substr(comma2 + 1, s.length() - comma2);
    s = s.substr(0, comma1);
    
    int pos1 = s.find(s1, 0);
    if (string::npos == pos1) {
        cout << "-1" << endl;
        return 0;
    }

    int pos2 = s.find(s2, pos1 + 1);
    int lastpos = pos2;
    while (string::npos != pos2) {
        lastpos = pos2;
        pos2 = s.find(s2, pos2 + 1);
    }
    if (string::npos == lastpos) {
        cout << "-1" << endl;
        return 0;
    }

    int ans = lastpos - (pos1 + s1.length());
    cout << ans << endl;


    return 0;
}