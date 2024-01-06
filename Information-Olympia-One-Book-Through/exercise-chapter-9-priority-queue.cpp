#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000;
struct node {
    int d, tot;
} b[MAX];


bool cmp(const node &a, const node &b) {
    if (a.tot != b.tot) return a.tot > b.tot;
    return a.d > b.d;
}

int gettot(int num) {
    int ans = 0;
    int tmp = num;
    for (int i = 2; num > 1 && i < tmp; i++) {
        if (num % i == 0) {
            ans++;
            while (num % i == 0) {
                num /= i;
            }
        }
    }
    return ans;
}

int n;

int main() {
    int l = 1;
    int r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10; j++) {
            r++;
            scanf("%d", &b[r].d);
            b[r].tot = gettot(b[r].d);
        }
        sort(b + l, b + r + 1, cmp);
        printf("%d %d\n", b[l].d, b[r].d);
        l++, r--;
    }

    return 0;
}
