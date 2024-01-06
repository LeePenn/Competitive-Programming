#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    int count = 0;
    while (getline(cin, s)) {
        cout << ++count << " " << s << endl;
    }


    return 0;
}