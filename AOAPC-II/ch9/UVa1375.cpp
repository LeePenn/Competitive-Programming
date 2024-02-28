#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <queue>

#define LL long long
#define ULL unsigned long long
using namespace std;
const int N = 50 + 5;
const int maxlen = 20 + 5;
const int maxs = 50 * 20 + 52 + 5;
int n, L, ns;
string rule[N];
string sym[maxs];
int car[maxs], cdr[maxs];
string dp[maxs][maxlen];
map<string, int> sym2id;
bool is_all_terminal(const string &s) {
    for (int i = 0; i < s.length(); ++i) {
        if (!(s[i] >= 'a' && s[i] <= 'z')) return 0;
    }
    return 1;
}
string min(const string &a, const string &b) {
    if (a == "-") return b;
    return a < b ? a : b;
}
struct Node {
    int x;
    string s;
    Node(int x, string s): x(x), s(s) {}
    bool operator <(const Node &rhs) const {
        return s > rhs.s;
    }
};
struct Transform {
    int target, empty;
    Transform(int t, int e): target(t), empty(e) {}
};
vector<Transform> tr[maxs];
bool vis[maxs];
int ID(const string &s) {
    if (!sym2id.count(s)) {
        sym[ns] = s;
        sym2id[s] = ns++;
    }
    return sym2id[s];
}
void add_intermediate_symbol(const string &S) {
    int s = ID(S);
    if (S.length() < 2) return;
    int h = ID(S.substr(0, 1));
    int t = ID(S.substr(1, S.length() - 1));
    tr[h].push_back(Transform(s, t));
    tr[t].push_back(Transform(s, h));
    car[s] = h;
    cdr[s] = t;
}
void search(int len) {
    memset(vis, 0, sizeof(vis));
    priority_queue<Node> q;
    for (int i = 0; i < ns; ++i) {
        if (dp[i][len] != "-") q.push(Node(i, dp[i][len]));
    }
    while (!q.empty()) {
        Node u = q.top(); q.pop();
        int x = u.x;
        string s = u.s;
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = 0; i < tr[x].size(); ++i) {
            int target = tr[x][i].target;
            int empty = tr[x][i].empty;
            if (dp[empty][0] == "" && (dp[target][len] == "-" || s < dp[target][len])) {
                dp[target][len] = s;
                q.push(Node(target, s));
            }
        }
    }
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  
  while (cin >> n >> L && n) {
    sym2id.clear();
    ns = 0;
    ID("");
    for (int i = 0; i < maxs; ++i) tr[i].clear();
    for (int i = 0; i < n; ++i) {
        cin >> rule[i];
        int left = ID(rule[i].substr(0, 1));
        int right = ID(rule[i].substr(2));
        tr[right].push_back(Transform(left, ID("")));
        int len = rule[i].length();
        for (int j = 2; j < len; ++j) {
            add_intermediate_symbol(rule[i].substr(j));
        }
    }
    for (int i = 0; i < ns; ++i) {
        for (int j = 0; j <= L; ++j) {
            dp[i][j] = "-";
        }
    }
    dp[0][0] = "";
    
    for (int j = 0; j <= L; ++j) {
        for (int i = 0; i < ns; ++i) {
            if (sym[i].length() == j && is_all_terminal(sym[i])) {
                dp[i][j] = sym[i];
            }
            if (sym[i].length() < 2) continue;
            int s1 = car[i], s2 = cdr[i];
            for (int k = 1; k < j; ++k) {
                if (dp[s1][k] != "-" && dp[s2][j - k] != "-") {
                    dp[i][j] = min(dp[i][j], dp[s1][k] + dp[s2][j - k]);
                }
            }
        }
        search(j);
    }
    cout << dp[ID("S")][L] << endl;
  }
  
  

  return 0;
}