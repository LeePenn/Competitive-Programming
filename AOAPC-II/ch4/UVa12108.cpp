// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 12;
struct Stu {
    int a, b, c;
}stu[N];
int n;
set<string> seen;

void encode(string& s) {
    for (int i = 1; i <= n; i++) {
        s += stu[i].c + '0';
    }
}

bool check(int id, int t) {
    string s;
    encode(s);
    if (seen.count(s)) {
        printf("Case %d: -1\n", id);
        return true;
    }
    seen.insert(s);
    int wake = 0, sleep = 0;
    
    for (int i = 1; i <= n; i++) {
        if (stu[i].c <= stu[i].a) wake++;
        else sleep++;
    }
    if (!sleep) {
        printf("Case %d: %d\n", id, t);
        return true;
    }
    for (int i = 1; i <= n; i++) {
        stu[i].c++;
        if (stu[i].c == stu[i].a + stu[i].b + 1) stu[i].c = 1;
        else if (stu[i].c == stu[i].a + 1 && wake >= sleep) stu[i].c = 1;
    }
    return false;
}

int main() {
    int id = 1;
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) scanf("%d %d %d", &stu[i].a, &stu[i].b, &stu[i].c);
        seen.clear();
        int t = 1;
        while (1) if (check(id, t++)) break;
        id++;
    }
    
    return 0;
}