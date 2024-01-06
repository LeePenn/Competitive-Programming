#include <bits/stdc++.h>

using namespace std;

struct pat {
    string name;
    int priority;
};
pat p[100000];
int n, t;
string op;

void push() {
    int son = t;
    while (son > 1) {
        int pa = son >> 1;
        if (p[pa].priority <= p[son].priority) {
            swap(p[pa], p[son]);
            son = pa;
        } else break;
    }
}

void get() {
    if (t < 1) {
        cout << "none" << endl;
        return;
    } 
    cout << p[1].name << ' ' << p[1].priority << endl;
    p[1] = p[t];
    t--;
    int pa = 1;
    while (pa <= t) {
        int son = pa << 1;
        if (son < t && p[son + 1].priority >= p[son].priority) son++;
        if (p[son].priority >= p[pa].priority) {
            swap(p[son], p[pa]);
            pa = son;
        } else break;
    }
}

void work() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> op;
        if (op == "push") {
            t++;
            cin >> p[t].name >> p[t].priority;
            push();
        } else {
            get();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    work();

    return 0;
}