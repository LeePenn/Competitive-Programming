#include <bits/stdc++.h>

using namespace std;

char s[1000];
int a[1000], b[1000], t1, t2;

void Push(int x, int flag) {
    if (flag) a[++t1] = x;
    else b[++t2] = x;
}

void Pop() {
    switch (b[t2]) {
        case '+':
            a[t1 - 1] += a[t1];
            break;
        case '-':
            a[t1 - 1] -= a[t1];
            break;
        case '*':
            a[t1 - 1] *= a[t1];
            break;
        case '/':
            a[t1 - 1] /= a[t1];
            break;
        case '^':
            a[t1 - 1] = pow(a[t1 - 1], a[t1]);
            break;
        default:
            break;
    }
    t1--;
    t2--;
}

int Opr(int x) {
    if (x == '+' || x == '-') return 0;
    if (x == '*' || x == '/') return 1;
    if (x == '^') return 2;
    return -1;
}

bool Check(int x) {
    if (Opr(x) <= Opr(b[t2])) return true;
    return false;
}

int main() {
    // meet ) or operator priority <= b[top], calc, else num -> a, op -> b
    scanf("%s", s);
    int l = strlen(s);
    s[l] = ')';
    Push('(', 0);
    
    for (int i = 0; i <= l; i++) {
        while (s[i] == '(') {
            Push(s[i], 0);
            i++;
        }
        int x = 0;
        while (isdigit(s[i])) {
            x = x * 10 + s[i] - '0';
            i++;
        }
        Push(x, 1);
        while (true) {
            if (s[i] == ')') {
                while (b[t2] != '(') {
                    Pop();
                }
                t2--;
            } else {
                while (Check(s[i])) Pop();
                Push(s[i], 0);
                break;
            }
            i++;
            if (i > l) break;
        }
    }
    
    printf("%d\n", a[1]);

    return 0;
}