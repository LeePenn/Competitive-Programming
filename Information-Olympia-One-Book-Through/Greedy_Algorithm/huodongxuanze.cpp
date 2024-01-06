#include <bits/stdc++.h>

using namespace std;

int n;
struct meeting {
    int begin, end;
}m[1000];

bool cmp(const meeting &m1, const meeting &m2) {
    return m1.end <= m2.end;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m[i].begin >> m[i].end;
    }
    sort(m + 1, m + n + 1, cmp);
    
    int ans = 1;
    int lastEnd = m[1].end;
    for (int i = 2; i <= n; i++) {
        if (m[i].begin > lastEnd) {
            ans++;
            lastEnd = m[i].end;
        }
    }
    cout << ans << endl;

    return 0;
}