#include <bits/stdc++.h>

using namespace std;

int prefer[6][6], stu[6], books[6], n;

void work(int s) {
    if (s == n + 1) {
        for (int i = 1; i <= n; i++) {
            printf("%d: %d\n", i, stu[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (books[i] || !prefer[s][i]) continue;
        stu[s] = i;
        books[i] = 1;
        work(s + 1);
        stu[s] = 0;
        books[i] = 0;
    }
    
    return;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) scanf("%d", &prefer[i][j]);
    }
    
    work(1);
    
    return 0;
}