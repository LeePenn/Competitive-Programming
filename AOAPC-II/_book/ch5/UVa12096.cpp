// Joker
#include <bits/stdc++.h>
using namespace std;
typedef set<int> Set;
map<Set, int> IDcache;
vector<Set> Setcache;
int T, n;

#define ALL(X) X.begin(), X.end()
#define INS(X) inserter(X, X.begin())

int ID(Set x) {
    if (IDcache.count(x)) return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x] = Setcache.size() - 1;
}

int main() {
    cin >> T;
    string op;
    while (T--) {
        stack<int> stk;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> op;
            if (op[0] == 'P') stk.push(ID(Set()));
            else if (op[0] == 'D') stk.push(stk.top());
            else {
                Set s1 = Setcache[stk.top()]; stk.pop();
                Set s2 = Setcache[stk.top()]; stk.pop();
                Set s;
                if (op[0] == 'U') set_union(ALL(s1), ALL(s2), INS(s));
                if (op[0] == 'I') set_intersection(ALL(s1), ALL(s2), INS(s));
                if (op[0] == 'A') {
                    s = s2;
                    s.insert(ID(s1));
                }
                stk.push(ID(s));
            }
            cout << Setcache[stk.top()].size() << endl;
        }
        cout << "***" << endl;
    }
    
    return 0;
}