#include <bits/stdc++.h>

using namespace std;

int a, b;

bool work(int a, int b) {
    if (a < b) swap(a, b);
    if (a % b == 0 || a / b >= 2) return true;
    return !work(a - b, b);
}

int main() {
    while (scanf("%d%d", &a, &b) == 2 && a && b) {
        if (work(a, b)) printf("win\n");
        else printf("lose\n");
    }

    return 0;
}