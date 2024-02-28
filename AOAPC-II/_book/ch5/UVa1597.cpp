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

typedef vector<int> IntVec;
typedef set<int> IntSet;
#define ALL(X) X.begin(), X.end()


IntSet emptyIntSet;

struct Doc {
    IntSet lines;
    map<string, IntSet> words;
    
    void AddLine(const string& s, int l) {
        lines.insert(l);
        string w;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isalpha(c)) w.push_back(tolower(c));
            else {
                if (!w.empty()) {
                    words[w].insert(l);
                    w.clear();
                }
            }
        }
        if (!w.empty()) words[w].insert(l);
    }
    
    const IntSet& FindWord(const string& w) {
        if (!words.count(w)) return emptyIntSet;
        return words[w];
    }
};

vector<Doc> docs;
vector<string> Lines;

ostream& operator << (ostream& os, const IntSet s) {
    for (IntSet::const_iterator it = s.begin(); it != s.end(); it++) {
        os << Lines[*it] << endl;
    }
    return os;
}

void parseQuery(const string& s, vector<string>& q) {
    q.clear();
    stringstream ss(s);
    string w;
    while (ss >> w) q.push_back(w);
}

void doQuery(const vector<string>& q) {
    string A = q.front(), B = q.back();
    bool isAnd = (q.size() == 3) && (q[1] == "AND");
    bool first = true;
    stringstream ss;
    switch (q.size()) {
        case 1:
            for (int i = 0; i < docs.size(); i++) {
                Doc& d = docs[i];
                const IntSet& ans = d.FindWord(A);
                if (ans.empty()) continue;
                
                if (first) first = false;
                else ss << "----------" << endl;
                ss << ans;
            }
            break;
        case 2:
            for (int i = 0; i < docs.size(); i++) {
                Doc& d = docs[i];
                const IntSet& ans = d.FindWord(B);
                if (!ans.empty()) continue;
                
                if (first) first = false;
                else ss << "----------" << endl;
                ss << d.lines;
            }
            break;
        case 3:
            for (int i = 0; i < docs.size(); i++) {
                Doc& d = docs[i];
                const IntSet& ansA = d.FindWord(A), ansB = d.FindWord(B);
                bool match;
                if (isAnd) match = (!ansA.empty()) && (!ansB.empty());
                else match = (!ansA.empty()) || (!ansB.empty());
                if (!match) continue;
                if (first) first = false;
                else ss << "----------" << endl;
                
                IntVec ans(ansA.size() + ansB.size());
                IntVec::iterator st = set_union(ALL(ansA), ALL(ansB), ans.begin());
                for (IntVec::iterator it = ans.begin(); it != st; it++) {
                    ss << Lines[*it] << endl;
                }
            }
            break;
        default:
            break;
    }
    const string& output = ss.str();
    if (output.empty()) cout << "Sorry, I found nothing." << endl;
    cout << output << "==========" << endl;
}

int main() {
    int n, m;
    cin >> n;
    docs.resize(n);
    string line;
    getline(cin, line);
    for (int i = 0; i < n; i++) {
        Doc& d = docs[i];
        while (1) {
            getline(cin, line);
            if (line == "**********") break;
            d.AddLine(line, Lines.size());
            Lines.push_back(line);
        }
    }
    
    cin >> m;
    getline(cin, line);
    vector<string> query;
    for (int i = 0; i < m; i++) {
        getline(cin, line);
        parseQuery(line, query);
        doQuery(query);
    }
  
    return 0;
}