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

int main() {
    set<string> dict;
    string word, left, right;
    while (cin >> word) dict.insert(word);
    //cout << dict.size() << endl;
    for (const auto& w : dict) {
        //cout << w << endl;
        for (int i = 1; i < w.length(); i++) {
            left = w.substr(0, i);
            right = w.substr(i, w.length() - i);
            if (dict.count(left) && dict.count(right)) {
                printf("%s\n", w.c_str());
                break;
            }
        }
    }
  
    return 0;
}