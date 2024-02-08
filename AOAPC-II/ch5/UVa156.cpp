// Joker
#include <bits/stdc++.h>
using namespace std;
map<string, int> cnt;
vector<string> words;

string work(const string& s) {
    string ans = s;
    for (int i = 0; i < ans.size(); i++) ans[i] = tolower(ans[i]);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s;
    while (cin >> s && s[0] != '#') {
        words.push_back(s);
        string r = work(s);
        if (!cnt.count(r)) cnt[r] = 0;
        cnt[r]++;
    }
    vector<string> ans;
    for (int i = 0; i < words.size(); i++) {
        if (cnt[work(words[i])] == 1) ans.push_back(words[i]);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) printf("%s\n", ans[i].c_str());
    return 0;
}