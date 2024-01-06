#include <bits/stdc++.h>

using namespace std;

int n;
struct Dis {
    int st, ed;
}d[10000];

bool cmp(const Dis &d1, const Dis &d2) {
    return d1.ed < d2.ed;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d[i].st >> d[i].ed;
    sort(d + 1, d + n + 1, cmp);
    
    int ans = 1;
    int num = d[1].ed;
    for (int i = 2; i <= n; i++) {
        if (num < d[i].st) {
            num = d[i].ed;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}