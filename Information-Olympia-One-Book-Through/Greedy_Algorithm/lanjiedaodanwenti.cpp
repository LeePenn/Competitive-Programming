#include <bits/stdc++.h>

using namespace std;

int n, a[1000], ans[1000];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ans[1] = a[1];
    int cnt = 1;
    for (int i = 2; i <= n; i++) {
        int minIdx = 0;
        for (int j = 1; j <= cnt; j++) {
            if (ans[j] >= a[i] && (minIdx == 0 || ans[j] < ans[minIdx])) {
                minIdx = j;
            }
        }
        if (minIdx == 0) {
            cnt++;
            ans[cnt] = a[i];
        } else {
            ans[minIdx] = a[i];
        }
    }
    cout << cnt << endl;

    return 0;
}