#include <bits/stdc++.h>

using namespace std;

int n;

void work(int n) {
    if (n == 1) {
        printf("2(0)");
        return;
    }
    if (n == 2) {
        printf("2");
        return;
    }
    int t = 0, m = 1;
    while (m <= n) {
        m *= 2;
        t++;
    }
    m /= 2, t--;
    n -= m;
    printf("2");
    if (t > 1) {
        printf("(");
        work(t);
        printf(")");
    }
    if (n > 0) {
        printf("+");
        work(n);
    }
    
    return;
}

int main() {
    scanf("%d", &n);
    work(n);


    return 0;
}