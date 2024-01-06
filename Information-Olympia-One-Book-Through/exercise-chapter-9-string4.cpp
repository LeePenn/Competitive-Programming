#include <bits/stdc++.h>

using namespace std;

int n;
string p, d;
string a[100001];

string _get();

int ab(string s) {
    int x;
    stringstream ss(s);
    ss >> x;
    return x;
}

string ba(int x) {
    string s;
    stringstream ss;
    ss << x;
    s = ss.str();
    return s;
}

string add() {
    string s1 = _get();
    string s2 = _get();
    if (s1.size() > 5 || s2.size() > 5) return s1 + s2;
    
    int a1 = ab(s1);
    int a2 = ab(s2);
    string b1 = ba(a1);
    string b2 = ba(a2);
    if (s1 == b1 && s2 == b2) return ba(a1 + a2);
    return s1 + s2;
}

string copy() {
    int c = ab(_get());
    int x = ab(_get());
    int y = ab(_get());
    return a[c].substr(x, y);
}

string find() {
    string s = _get();
    int x = ab(_get());
    int y = a[x].find(s);
    if (y == string::npos) return ba(a[x].size());
    return ba(y);
}

string rfind() {
    string s = _get();
    int x = ab(_get());
    int y = a[x].rfind(s);
    if (y == string::npos) return ba(a[x].size());
    return ba(y);
}

void insert() {
    string s = _get();
    int c = ab(_get());
    int x = ab(_get());
    a[c].insert(x, s);
}

void reset() {
    string s = _get();
    int x = ab(_get());
    a[x] = s;
}

void print() {
    int x = ab(_get());
    cout << a[x] << '\n';
}

void printall() {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << '\n';
    }
    
}

string _get() {
    string s;
    cin >> s;
    if (s == "add") return add();
    if (s == "copy") return copy();
    if (s == "find") return find();
    if (s == "rfind") return rfind();
    if (s == "reset") reset();
    if (s == "print") print();
    if (s == "insert") insert();
    if (s == "printall") printall();
    
    return s;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (true) {
        p = _get();
        if (p == "over") break;
    }
    
    return 0;
}