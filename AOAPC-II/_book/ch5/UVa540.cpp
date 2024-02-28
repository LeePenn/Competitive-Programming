// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
int T;
map<int, int> team;

int main() {
    int id = 0;
    while (scanf("%d", &T) == 1 && T != 0) {
        printf("Scenario #%d\n", ++id);
        for (int i = 0; i < T; i++) {
            int n;
            scanf("%d", &n);
            for (int j = 1; j <= n; j++) {
                int x;
                scanf("%d", &x);
                team[x] = i;
            }
        }
        queue<int> q, qt[N];
        string op;
        while (cin >> op && op[0] != 'S') {
            if (op[0] == 'E') {
                int x;
                scanf("%d", &x);
                int t = team[x];
                if (qt[t].empty()) {
                    qt[t].push(x);
                    q.push(t);
                } else {
                    qt[t].push(x);
                }
            } else {
                int first = q.front();
                printf("%d\n", qt[first].front());
                qt[first].pop();
                if (qt[first].empty()) q.pop();
            }
        }
        puts("");
    }
    
    return 0;
}