#include <bits/stdc++.h>

using namespace std;

string a[100001];

bool cmp(const string &s1, const string &s2) {
    int n = min(s1.size(), s2.size()); 
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) return s1[i] > s2[i];
    }
    return s1.size() > s2.size();
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }


    return 0;
}