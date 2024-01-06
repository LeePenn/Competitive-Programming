#include <bits/stdc++.h>

using namespace std;

// a[] 打水时间 t[] 队列时间
int a[100], t[100], n, r;
int ans;

int main() {
    cin >> n >> r;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    memset(t, 0, sizeof(t));
    int cnt = 1, r_num = 1;
    ans = 0;
    while (cnt <= n) {
        ans += t[r_num] + a[cnt];
        t[r_num] += a[cnt];
        r_num++;
        if (r_num > r) r_num = 1;
        cnt++;
    }
    cout << ans << endl;


    return 0;
}