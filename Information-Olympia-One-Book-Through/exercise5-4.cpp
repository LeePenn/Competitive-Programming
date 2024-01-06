#include <bits/stdc++.h>

using namespace std;

string s1, s2;

int main() {
    getline(cin, s1);
    getline(cin, s2);

    int diff = 'a' - 'A';
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] >= 'A' && s1[i] <= 'Z') {
            s1[i] += diff;
        }
    }
    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] >= 'A' && s2[i] <= 'Z') {
            s2[i] += diff;
        }
    }
    if (s1 > s2) printf(">\n");
    else if (s1 < s2) printf("<\n");
    else printf("=\n");

    return 0;
}