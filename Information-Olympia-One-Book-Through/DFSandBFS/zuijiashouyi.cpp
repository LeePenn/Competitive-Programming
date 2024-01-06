#include <bits/stdc++.h>

using namespace std;

int salary[10][10], jobs[10], n, total, ans[10];

void print(int a[]) {
    for (int i = 1; i <= n; i++) printf("%d:%d\n", i, ans[i]);
    printf("\n");
}

void calc(int w, int sal) {
    if (w == n + 1) {
        if (sal > total) {
            total = sal;
            for (int i = 1; i <= n; i++) ans[jobs[i]] = i;
        }
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (jobs[i]) continue;
        
        jobs[i] = w;
        sal += salary[w][i];
        calc(w + 1, sal);
        jobs[i] = 0;
        sal -= salary[w][i];
    }
    
    return;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) scanf("%d", &salary[i][j]);
    }
    
    calc(1, 0);
    printf("%d\n", total);
    print(ans);


    return 0;
}