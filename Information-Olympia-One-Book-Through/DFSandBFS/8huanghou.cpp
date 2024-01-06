#include <bits/stdc++.h>

using namespace std;

int ans[9], c[9], d[20], ad[20], n;

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i] == j) cout << '#';
            else cout << '.';
        }
        cout << endl;
    }
    cout << endl;

    return;
}

void work(int i) {
    if (i == n + 1) {
        print();
        return;
    }
    
    for (int j = 1; j <= n; j++) {
        if (c[j] || d[i - j + n] || ad[i + j]) continue;
        ans[i] = j;
        c[j] = 1;
        d[i - j + n] = 1;
        ad[i + j] = 1;
        work(i + 1);
        ans[i] = 0;
        c[j] = 0;
        d[i - j + n] = 0;
        ad[i + j] = 0;
    }

    return;
}

int main() {
    n = 8;
    work(1);


    return 0;
}