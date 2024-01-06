#include <bits/stdc++.h>

using namespace std;

int n, ans[100], tot;

void print(int a[], int cnt) {
    for (int i = 1; i < cnt; i++) printf("%d+", a[i]);
    printf("%d\n", a[cnt]);

    return;
}

void work(int n, int cnt) {
    if (n == 0 && cnt > 2) {
        print(ans, cnt - 1);
        tot++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (i < ans[cnt - 1]) continue;
        ans[cnt] = i;
        work(n - i, cnt + 1);
    }


    return;
}

int main() {
    scanf("%d", &n);
    memset(ans, 0, sizeof(ans));
    work(n, 1);
    printf("%d\n", tot);

    return 0;
}