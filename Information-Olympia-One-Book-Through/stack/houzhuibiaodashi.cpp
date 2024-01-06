#include <bits/stdc++.h>

using namespace std;

char s[1000];

int calc() {
    int l = strlen(s);
    int a[1000];
    // must initialize
    memset(a, 0, sizeof(a));
    int top = 0;
    int i = 0;
    while (i <= l - 2) {
        switch (s[i]) {
            case '+': a[top - 1] += a[top]; top--; break;
            case '-': a[top - 1] -= a[top]; top--; break;
            case '*': a[top - 1] *= a[top]; top--; break;
            case '/': a[top - 1] /= a[top]; top--; break;
            default: int x = 0; while (s[i] != ' ') x = x * 10 + s[i++] - '0'; a[++top] = x; break;
        }
        i++;
    }
    return a[top];
}

int main() {
    gets(s);
    printf("%d\n", calc());

    return 0;
}