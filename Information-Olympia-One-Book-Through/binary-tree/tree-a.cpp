#include <bits/stdc++.h>

using namespace std;

int a[100], lc[100], rc[100], n, num, ans;

void work(int c) {
    if (!a[c]) return;
    
    work(lc[c]);
    ans++;
    if (a[c] == num) {
        cout << ans << endl;
        return;
    }
    work(rc[c]);
}

int main() {
    cin >> n >> num;
    for (int i = 1; i <= n; i++) cin >> a[i] >> lc[i] >> rc[i];
    
    work(1);

    return 0;
}