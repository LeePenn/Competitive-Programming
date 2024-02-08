// Joker
#include <bits/stdc++.h>
using namespace std;
string line;
vector<string> grid;
vector<pair<int, string> > a, d;
int n, m, cnt;

bool check_left(int x, int y) {
    if (y - 1 < 0 || grid[x][y - 1] == '*') return 1;
    return 0;
}

bool check_upper(int x, int y) {
    if (x - 1 < 0 || grid[x - 1][y] == '*') return 1;
    return 0;
}

void add_across(int x, int y) {
    string ans = "";
    while (y < m && grid[x][y] != '*') ans = ans + grid[x][y], y++;
    a.push_back(make_pair(cnt, ans));
}

void add_down(int x, int y) {
    string ans = "";
    while (x < n && grid[x][y] != '*') ans = ans + grid[x][y], x++;
    d.push_back(make_pair(cnt, ans));
}

int main() {
    int id = 0;
    while (scanf("%d%d", &n, &m) && n) {
        grid.clear();
        a.clear();
        d.clear();
        getline(cin, line);
        for (int i = 0; i < n; i++) {
            getline(cin, line);
            grid.push_back(line);
        }
        
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '*') continue;
                else if (check_left(i, j) || check_upper(i, j)) {
                    cnt++;
                    if (check_left(i, j)) add_across(i, j);
                    if (check_upper(i, j)) add_down(i, j);
                }
            }
        }
        if (id > 0) cout << endl;
        printf("puzzle #%d:\n", ++id);
        puts("Across");
        for (int i = 0; i < a.size(); i++) {
            printf("%3d.%s\n", a[i].first, a[i].second.c_str());
        }
        puts("Down");
        for (int i = 0; i < d.size(); i++) {
            printf("%3d.%s\n", d[i].first, d[i].second.c_str());
        }
    }
    return 0;
}