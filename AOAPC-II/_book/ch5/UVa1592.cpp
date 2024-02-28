// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 10003;
string s[N][12];
//int s[N][12];
int n, m, cnt;
//map<string, int> mp;

typedef pair<int, int> PII;

//int ID(const string& s) {
    //if (mp.count(s)) return mp[s];
    //mp[s] = ++cnt;
    //return cnt;
//}

void find() {
    for (int c1 = 0; c1 < m; c1++) {
        for (int c2 = c1 + 1; c2 < m; c2++) {
            map<string, int> seen;
            for (int r = 0; r < n; r++) {
                string t =  s[r][c1] + ',' + s[r][c2];
                if (seen.count(t)) {
                    printf("NO\n");
                    printf("%d %d\n", seen[t] + 1, r + 1);
                    printf("%d %d\n", c1 + 1, c2 + 1);
                    return;
                }
                seen[t] = r;
            }
        }
    }
    puts("YES");
}

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        cnt = 0;
        if (ss >> n >> m && n && m) {
            for (int i = 0; i < n; i++) {
                getline(cin, line);
                int p = -1;
                for (int j = 0; j < m; j++) {
                    int cur = line.find(',', p + 1);
                    if (cur == string::npos) cur = line.length();
                    s[i][j] = line.substr(p + 1, cur - p - 1);
                    //s[i][j] = ID(line.substr(p + 1, cur - p - 1));
                    p = cur;
                }
            }
            find();
        }
    }
    
    return 0;
}