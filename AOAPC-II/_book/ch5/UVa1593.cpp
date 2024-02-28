// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 1024;
vector<string> line_words[N];
int line_len[N];

template <typename T>
ostream& operator << (ostream& os, vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << ' ';
    }
    return os;
}

int main() {
    string line;
    int line_cnt = 0;
    memset(line_len, 0, sizeof(line_len));
    while (getline(cin, line)) {
        stringstream s(line);
        string word;
        int word_cnt = 0;
        while (s >> word) {
            line_len[word_cnt] = max(line_len[word_cnt], (int)word.length());
            line_words[line_cnt].push_back(word);
            word_cnt++;
        }
        line_cnt++;
    }
    for (int i = 0; i < line_cnt; i++) {
        for (int j = 0; j < line_words[i].size(); j++) {
            cout << left << setw(j < line_words[i].size() - 1 ? line_len[j] + 1 : 0) << line_words[i][j];
        }
        cout << endl;
    }
  
    return 0;
}