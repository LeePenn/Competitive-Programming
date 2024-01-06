#include <bits/stdc++.h>

using namespace std;

map<string, string> d;

string a, b, s;

int main() {
    while (getline(cin, s)) {
        if (s == "") break;
        a = s.substr(0, s.find(' '));
        b = s.substr(s.find(' ') + 1, s.size());
        d[b] = a; 
    }
    
    while (getline(cin, s)) {
        if (d[s] == "") cout << "eh" << endl;
        else cout << d[s] << endl;
        
    }
    
    return 0;
}