// Joker
#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator << (ostream& os, vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << ' ';
    }
    return os;
}

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

const double eps = 1e-7;
int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}
int cmp(double x, double y) {
    return dcmp(x - y);
}

bool inRange(double x, double l, double r) {
    if (dcmp(l - r) > 0) return inRange(x, r, l);
    return dcmp(x - l) >= 0 && dcmp(r - x) >= 0;
}

bool inArea(const Point& p, const Point& l, const Point& r) {
    return inRange(p.x, l.x, r.x) && inRange(p.y, l.y, r.y);
}

istream& operator >> (istream& is, Point& p) {
    return is >> p.x >> p.y;
}

Point operator + (const Point& p1, const Point& p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
}

Point operator - (const Point& p1, const Point& p2) {
    return Point(p1.x - p2.x, p1.y - p2.y);
}

Point operator * (const Point& p, double x) {
    return Point(p.x * x, p.y * x);
}

double Dot(const Point& A, const Point& B) {
    return A.x * B.x + A.y * B.y;
}

double Dist2(const Point& A, const Point& B) {
    return Dot(A - B, A - B);
}

struct Map {
    string name;
    Point corner1, corner2, center, lowerRight;
    double area, width, height, ratio, minX;
    void init() {
        center = (corner1 + corner2) * 0.5;
        width = fabs(corner1.x - corner2.x);
        height = fabs(corner1.y - corner2.y);
        area = width * height;
        ratio = fabs(height / width - 0.75);
        minX = center.x - width / 2;
        lowerRight.x = center.x + width / 2;
        lowerRight.y = center.y + height / 2;
    }
};

vector<Map> maps;
map<string, Point> locIndice;

struct mapComp {
    Point loc;
    
    bool operator () (int i1, int i2) {
        const Map& m1 = maps[i1];
        const Map& m2 = maps[i2];
        int cr;
        cr = cmp(m1.area, m2.area);
        if (cr > 0) return true;
        if (cr < 0) return false;
        
        cr = cmp(Dist2(loc, m1.center), Dist2(loc, m2.center));
        if (cr > 0) return true;
        if (cr < 0) return false;
        
        cr = cmp(m1.ratio, m2.ratio);
        if (cr > 0) return true;
        if (cr < 0) return false;
        
        cr = cmp(Dist2(loc, m1.lowerRight), Dist2(loc, m2.lowerRight));
        if (cr > 0) return false;
        if (cr < 0) return true;
        
        cr = cmp(m1.minX, m2.minX);
        if (cr > 0) return true;
        if (cr < 0) return false;
        
        return true;
    }
};

void getMaps(const Point& loc, vector<int>& mis, vector<int>& level) {
    mis.clear();
    mapComp mc;
    mc.loc = loc;
    for (int i = 0; i < maps.size(); i++) {
        Map& m = maps[i];
        if (inArea(loc, m.corner1, m.corner2)) {
            mis.push_back(i);
        }
    }
    sort(mis.begin(), mis.end(), mc);
    level.clear();
    level.assign(mis.size(), 1);
    
    for (int i = 0; i < mis.size(); i++) {
        if (!i) continue;
        Map& m = maps[mis[i]];
        Map& pm = maps[mis[i - 1]];
        int c = cmp(m.area, pm.area);
        level[i] = level[i - 1];
        if (c < 0) level[i]++;
    }
}

void doRequest(const string& name, int level) {
    cout << name << " at detail level " << level;
    
    if (!locIndice.count(name)) {
        cout << " unknown location" << endl;
        return;
    }
    
    vector<int> mis, levels;
    getMaps(locIndice[name], mis, levels);
    if (mis.empty()) {
        cout << " no map contains that location" << endl;
        return;
    }
    int maxLevel = levels.back();
    if (maxLevel < level) {
        cout << " no map at that detail level; using " << maps[mis.back()].name << endl;
    } else {
        vector<int>::iterator it = upper_bound(levels.begin(), levels.end(), level);
        cout << " using " << maps[mis[it - levels.begin() - 1]].name << endl;
    }
}


int main() {
    string buf;
    getline(cin, buf);
    while (1) {
        Map m;
        cin >> m.name;
        if (m.name == "LOCATIONS") break;
        cin >> m.corner1 >> m.corner2;
        m.init();
        maps.push_back(m);
    }
    
    Point loc;
    string name;
    while (1) {
        cin >> name;
        if (name == "REQUESTS") break;
        cin >> loc;
        locIndice[name] = loc;
    }
    
    while (1) {
        cin >> name;
        if (name == "END") break;
        int level;
        cin >> level;
        doRequest(name, level);
    }
    
    
  
    return 0;
}
```


```cpp
// Joker
#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator << (ostream& os, vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << ' ';
    }
    return os;
}

const double eps = 1e-7;

int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

int cmp(double x, double y) {
    return dcmp(x - y);
}



struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}    
};

istream& operator >> (istream& is, Point& p) {
    return is >> p.x >> p.y;
}

Point operator + (const Point& p1, const Point& p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
}

Point operator - (const Point& p1, const Point& p2) {
    return Point(p1.x - p2.x, p1.y - p2.y);
}

Point operator * (const Point& p, double x) {
    return Point(p.x * x, p.y * x);
}

double Dot(const Point& p1, const Point& p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

double Dist2(const Point& p1, const Point& p2) {
    return Dot(p1 - p2, p1 - p2);
}

bool inRange(double x, double l, double r) {
    if (dcmp(l - r) > 0) return inRange(x, r, l);
    return dcmp(x - l) >= 0 && dcmp(r - x) >= 0;
}

bool inArea(const Point& p, const Point& l, const Point& r) {
    return inRange(p.x, l.x, r.x) && inRange(p.y, l.y, r.y);
}

map<string, Point> locations;

struct Map {
    string name;
    Point corner1, corner2, center, lowerRight;
    double area, width, height, ratio, minX;
    
    void init() {
        center = (corner1 + corner2) * 0.5;
        width = fabs(corner1.x - corner2.x);
        height = fabs(corner1.y - corner2.y);
        area = width * height;
        ratio = fabs(height / width - 0.75);
        lowerRight.x = center.x + width * 0.5;
        lowerRight.y = center.y + height * 0.5;
        minX = center.x - width * 0.5;
    }
};

vector<Map> maps;

struct mapComp {
    Point loc;
    
    bool operator () (int i1, int i2) {
        const Map& m1 = maps[i1];
        const Map& m2 = maps[i2];
        
        int cr = cmp(m1.area, m2.area);
        if (cr > 0) return true;
        if (cr < 0) return false;
        
        cr = cmp(Dist2(loc, m1.center), Dist2(loc, m2.center));
        if (cr > 0) return true;
        if (cr < 0) return false;
        
        cr = cmp(m1.ratio, m2.ratio);
        if (cr > 0) return true;
        if (cr < 0) return false;
        
        cr = cmp(Dist2(loc, m1.lowerRight), Dist2(loc, m2.lowerRight));
        if (cr > 0) return false;
        if (cr < 0) return true;
        
        cr = cmp(m1.minX, m2.minX);
        if (cr > 0) return true;
        if (cr < 0) return false;
        
        return true;
    }
};

void getMaps(const string& name, vector<int>& ms, vector<int>& levels) {
    ms.clear();
    const Point& loc = locations[name];
    mapComp mc;
    mc.loc = loc;
    for (int i = 0; i < maps.size(); i++) {
        if (inArea(loc, maps[i].corner1, maps[i].corner2)) 
            ms.push_back(i);
    }
    
    if (ms.empty()) return;
    
    sort(ms.begin(), ms.end(), mc);
    levels.clear();
    levels.assign(ms.size(), 1);
    for (int i = 0; i < ms.size(); i++) {
        if (!i) continue;
        const Map& m1 = maps[ms[i]];
        const Map& m2 = maps[ms[i - 1]];
        levels[i] = levels[i - 1];
        int cr = cmp(m1.area, m2.area);
        if (cr < 0) levels[i]++;
    }
    
}

void doRequest(const string& name, int level) {
    cout << name << " at detail level " << level;
    if (!locations.count(name)) {
        cout << " unknown location" << endl;
        return;
    }
    
    vector<int> ms, levels;
    getMaps(name, ms, levels);
    if (ms.empty()) {
        cout << " no map contains that location" << endl;
        return;
    }
    
    int maxLevel = levels.back();
    if (maxLevel < level) {
        cout << " no map at that detail level; using " << maps[ms.back()].name << endl;
        return;
    }
    
    vector<int>::iterator it = upper_bound(levels.begin(), levels.end(), level);
    cout << " using " << maps[ms[it - levels.begin() - 1]].name << endl;
}

int main() {
    string buf;
    getline(cin, buf);
    while (1) {
        Map m;
        cin >> buf;
        if (buf == "LOCATIONS") break;
        m.name = buf;
        cin >> m.corner1 >> m.corner2;
        m.init();
        maps.push_back(m); 
    }
    
    while (1) {
        Point loc;
        cin >> buf;
        if (buf == "REQUESTS") break;
        cin >> loc;
        locations[buf] = loc;
    }
    
    int level;
    while (1) {
        cin >> buf;
        if (buf == "END") break;
        cin >> level;
        doRequest(buf, level);
    }
    
  
    return 0;
}