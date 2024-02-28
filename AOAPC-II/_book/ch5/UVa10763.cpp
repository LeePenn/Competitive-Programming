// Joker
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> IPair;
map<IPair, int> p;
int n;

template <typename T>
ostream& operator << (ostream& os, vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << ' ';
    }
    return os;
}

int main() {
    int x, y;
    while (cin >> n && n) {
        p.clear();
        for (int i = 1; i <= n; i++) {
            cin >> x >> y;
            IPair cur = make_pair(x, y);
            p[cur]++;
        }
        bool ok = true;
        for (const auto& a : p) {
            IPair cur = make_pair(a.first.second, a.first.first);
            if (p[cur] != a.second) {
                ok = false;
                break;
            };
        }
        if (!ok) puts("NO");
        else puts("YES");
    }
  
    return 0;
}