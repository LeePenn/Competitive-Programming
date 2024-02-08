#include <bits/stdc++.h>
using namespace std;
struct P {
    int x, y;
};
vector<P> b;
int x, y;
istream& operator >> (istream& is, P& p) {
    return is >> p.x >> p.y;
}

int main() {
    while (1) {
        b.clear();
        for (int i = 1; i <= 6; i++) {
            P p;
            if (!(cin >> p)) return 0;
            if (p.x > p.y) swap(p.x, p.y);
            b.push_back(p);
            
        }
        sort(b.begin(), b.end(), [](const P& p1, const P& p2) {
            return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
        });
        bool flag = true;
        for (int i = 0; i < 5; i += 2) {
            if (b[i].x != b[i + 1].x || b[i].y != b[i + 1].y) {
                flag = false;
                break;
            }
        }
        if ((b[1].x != b[3].x || b[3].y != b[5].y || b[1].y != b[5].x)) flag = false;
        flag ? puts("POSSIBLE") : puts("IMPOSSIBLE");
    }
    
    return 0;
}