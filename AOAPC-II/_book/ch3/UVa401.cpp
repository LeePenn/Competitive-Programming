// Joker
#include <bits/stdc++.h>
using namespace std;
const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[] = {
    "not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"
};

char r(char c) {
    if (isalpha(c)) return rev[c - 'A'];
    return rev[c - '0' + 25];
}

int main() {
    char s[30];
    while (scanf("%s", s) == 1) {
        int len = strlen(s);
        int p = 1, m = 1;
        for (int i = 0; i < (len + 1) / 2; i++) {
            if (s[i] != s[len - i - 1]) p = 0;
            if (r(s[i]) != s[len - i - 1]) m = 0;
        }
        printf("%s -- is %s.\n\n", s, msg[2 * m + p]);
    }
    return 0;
}