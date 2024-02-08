// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 1024;
const double eps = 1e-7;
int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}
int T, n;
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) {
        this->x = x;
        this->y = y;
    }
    bool operator < (const Point& o) const {
        return dcmp(x - o.x) < 0 || (dcmp(x - o.x) == 0 && dcmp(y - o.y) < 0);
    }
}p[N];


template <typename T>
ostream& operator << (ostream& os, vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << ' ';
    }
    return os;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        double sx = 0;
        set<Point> seen;
        for (int i = 1; i <= n; i++) {
            scanf("%lf %lf", &p[i].x, &p[i].y);
            sx += p[i].x;
            seen.insert(p[i]);
        }
        sx /= n;
        bool mirror = true;
        for (int i = 1; i <= n; i++) {
            if (!dcmp(p[i].x - sx)) continue;
            Point p1(2 * sx - p[i].x, p[i].y);
            if (!seen.count(p1)) {
                mirror = false;
                break;
            }
        }
        puts(mirror ? "YES" : "NO");
    }
  
    return 0;
}