#include <bits/stdc++.h>

using namespace std;

int n, r, ans[1000];
bool b[1000];

void print(int a[]) {
    for (int i = 1; i <= r; i++) printf("%d ", a[i]);
    printf("\n");
    return;
}

void work(int cnt) {
    if (cnt == r) {
        print(ans);
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (b[i]) continue;
        b[i] = true;
        cnt++;
        ans[cnt] = i;
        work(cnt);
        b[i] = false;
        cnt--;
    }
    
    
    return;
}

int main() {
    scanf("%d%d", &n, &r);
    memset(b, false, sizeof(b));
    work(0);

    return 0;
}