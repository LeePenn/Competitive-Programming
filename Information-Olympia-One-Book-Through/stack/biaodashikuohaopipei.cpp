#include <bits/stdc++.h>

using namespace std;

char a[255];
char s[255];

int main() {
    gets(a);
    int l = strlen(a);
    int i = 0;
    int top = 0;
    while (i <= l - 2) {
        if (a[i] == '(') {
            s[++top] = '(';
        } else if (a[i] == ')') {
            if (top == 0) {
                printf("NO\n");
                return 0;
            }
            top--;
        }
        i++;
    }
    if (top == 0) printf("YES\n");
    else printf("NO\n");

    return 0;
}