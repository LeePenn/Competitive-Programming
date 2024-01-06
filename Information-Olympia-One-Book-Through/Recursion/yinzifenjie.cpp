#include <bits/stdc++.h>

using namespace std;

int n;

void work(int n) {
    int i = -1;
    bool prime = true;
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            prime = false;
            break;
        }
    }
    if (prime) {
        printf("%d", n);
        return;
    }
    int m = 0;
    while (n % i == 0) {
        n /= i;
        m++;
    }
    printf("%d", i);
    if (m > 1) printf("^%d", m);
    if (n >= 2) {
        printf("*");
        work(n);
    }

    return;
}

int main() {
    scanf("%d", &n);
    work(n);


    return 0;
}