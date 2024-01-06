#include <bits/stdc++.h>

using namespace std;

int t, n, ans;

void ac(int num, int c) {
    if (num == 1) {
        ans++;
        return;
    }
    
    for (int i = c; i <= num; i++) {
        if (num % i == 0) {
            ac(num / i, i);
        }
    }

    return;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        ans = 0;
        ac(n, 2);
        printf("%d\n", ans);
    }


    return 0;
}
