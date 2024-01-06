#include <bits/stdc++.h>

using namespace std;

struct pond {
    int fish, dim;
};
pond p[100];
int n, f[100], d[100], t[100], T;

void heapify(int n, int pa) {
    pond temp = p[pa];
    int son = pa << 1;
    while (son <= n) {
        if (son < n && p[son + 1].fish >= p[son].fish) son++;
        if (p[pa].fish > p[son].fish) break;
        p[pa] = p[son];
        pa = son;
        son <<= 1;
    }
    p[pa] = temp;
}

void work() {
    int ans = 0;
    int walkTime = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            p[j].fish = f[j], p[j].dim = d[j];
        }
        for (int j = 1; j <= i / 2; j++) heapify(i, j);
        
        int time = T - walkTime;
        int curmax = 0;
        while (time > 0 && p[1].fish > 0) {
            curmax += p[1].fish;
            p[1].fish -= p[1].dim;
            heapify(i, 1);
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