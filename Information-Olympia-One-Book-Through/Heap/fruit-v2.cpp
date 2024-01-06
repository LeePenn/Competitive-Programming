#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
    ios::sync_with_stdio(false);
    int x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        q.push(x);
    }
    int ans = 0;
    while (q.size() > 1) {
        int t1 = q.top(); q.pop();
        int t2 = q.top(); q.pop();
        ans += t1 + t2;
        q.push(t1 + t2);
    }
    
    cout << ans << endl;
    
    return 0;
}