#include <bits/stdc++.h>
using namespace std;
char c;

int main() {
    char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    int i;
    while ((c = getchar()) != EOF) {
        for (i = 1; s[i] && s[i] != c; i++);
        if (s[i]) putchar(s[i - 1]);
        else putchar(c);
    }
    return 0;
}