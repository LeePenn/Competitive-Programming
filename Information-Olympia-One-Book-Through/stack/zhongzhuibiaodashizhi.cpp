#include <bits/stdc++.h>

using namespace std;

stack<int> a;
stack<char> b;
char s[100000];

int Opr(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

bool Check(char c) {
    return Opr(c) <= Opr(b.top());
}

int ksm(int x, int y) {
    int ret = 1;
    while (y) {
        if (y&1) ret *= x;
        x *= x;
        y >>= 1;
    }
    return ret;
}

void calc() {
    int x = a.top();a.pop();
    int y = a.top();a.pop();
    switch (b.top()) {
        case '+': 
            a.push(y + x);
            break;
        case '-': 
            a.push(y - x);
            break;
        case '*': 
            a.push(y * x);
            break;
        case '/': 
            a.push(y / x);
            break;
        case '^': 
            a.push(ksm(y, x));
            break;
        default: 
            break;
    }
    b.pop();
}

int main() {
    scanf("%s", s);
    int l = strlen(s) - 1;
    s[l] = ')';
    b.push('(');
    for (int i = 0; i <= l; i++) {
        while (s[i] == '(') {
            b.push(s[i]);
            i++;
        }
        if (!isdigit(s[i])) {
            printf("NO");
            return 0;
        }
        int x = 0;
        while (isdigit(s[i])) {
            x = x * 10 + s[i] - '0';
            i++;
        }
        a.push(x);
        while (true) {
            if (s[i] == ')') {
                while (b.top() != '(') {
                    calc();
                }
                b.pop();
            } else {
                while (Check(s[i])) {
                    calc();
                }
                b.push(s[i]);
                break;
            }
            i++;
            if (i > l) break;
        }
    }
    if (b.size() != 0) printf("NO\n");
    else printf("%d\n", a.top());

    return 0;
}