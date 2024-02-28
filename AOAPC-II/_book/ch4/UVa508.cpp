// Joker
#include <bits/stdc++.h>
using namespace std;
unordered_map<char, string> morse;
unordered_map<string, vector<string> > context;

bool isPrefixOf(const string& s1, const string& s2) {
    int l1 = s1.size(), l2 = s2.size();
    if (l1 > l2) return 0;
    for (int i = 0; i < l1; i++) {
        if (s1[i] != s2[i]) return 0;
    }
    return 1;
}

void solve(const string& m) {
    if (context.count(m)) {
        printf("%s", context[m].front().c_str());
        if (context[m].size() > 1) printf("!");
        puts("");
        return;
    }
    map<int, string> ans;
    for (const auto& p : context) {
        const string& cm = p.first;
        if (isPrefixOf(m, cm)) ans[cm.size() - m.size()] = p.second.front();
        else if (isPrefixOf(cm, m)) ans[m.size() - cm.size()] = p.second.front();
    }
    cout << ans.begin()->second << "?" << endl;
}

int main() {
    string C, M;
    while (cin >> C && C != "*") {
        cin >> M;
        morse[C[0]] = M;
    }
    while (cin >> C && C != "*") {
        M.clear();
        for (int i = 0; i < C.size(); i++) {
            M += morse[C[i]];
        }
        context[M].push_back(C);
    }
    while (cin >> M && M != "*") solve(M);
    
    return 0;
}