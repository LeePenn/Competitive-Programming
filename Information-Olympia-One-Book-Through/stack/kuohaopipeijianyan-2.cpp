#include <bits/stdc++.h>

using namespace std;

char a[255];
stack<char> s;

int main() {
    gets(a);
    int l = strlen(a);
    int i = 0;
    while (i < l) {
        if (a[i] == '(' || a[i] == '[') {
            s.push(a[i]);
        } else if (a[i] == ')') {
            if (s.empty() || s.top() != '(') {
                printf("Wrong\n");
                return 0;
            }
            s.pop();
        } else if (a[i] == ']') {
            if (s.empty() || s.top() != '[') {
                printf("Wrong\n");
                return 0;
            }
            s.pop();
        }
        i++;
    }
    if (s.empty()) printf("OK\n");
    else printf("Wrong\n");

    return 0;
}