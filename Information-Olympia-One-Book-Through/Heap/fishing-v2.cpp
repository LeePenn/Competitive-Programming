#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int,int> > pq;
int n, f[100], d[100], t[100], T;

void work() {
    int walkTime = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        pq = priority_queue<pair<int,int> >();
        for (int j = 1; j <= i; j++) {
            pq.push(make_pair(f[j], d[j]));
        }
        int time = T - walkTime;
        int curmax = 0;
        while (time > 0 && pq.top().first > 0) {
            int curf = pq.top().first, curd = pq.top().second;
            curmax += pq.top().first; pq.pop();
            pq.push(make_pair(curf - curd, curd));
            time--;
        }
        if (curmax > ans) ans = curmax;
        walkTime += t[i];
    }
    cout << ans << endl;

}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> f[i];
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i < n; i++) cin >> t[i];
    cin >> T;
    work();

    return 0;
}