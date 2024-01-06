#include <bits/stdc++.h>

#define ll long long 

using namespace std;

int n, ans;
ll a[20], res[20];

ll gcd(ll a, ll b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

void work(int g, int idx) {
    if (idx == n + 1) {
        ans = min(ans, g);
        return;
    }
    for (int i = idx; i <= n; i++) {
        if (gcd(res[g], a[i]) == 1) {
            res[g] *= a[i];
            work(g, idx + 1);
            res[g] /= a[i];
        }
        res[g + 1] *= a[i];
        work(g + 1, idx + 1);
        res[g + 1] /= a[i];
    }   
    
    return;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        res[i] = 1;
    }
    sort(a + 1, a + n + 1);
    ans = n;
    
    work(1, 1);
    printf("%d\n", ans);



    return 0;
}