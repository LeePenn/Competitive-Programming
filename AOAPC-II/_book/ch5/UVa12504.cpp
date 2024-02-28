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

int T;

void parse(const string& line, map<string, string>& dict) {
    string key, value;
    int last_pos = 1;
    for (int i = 0; ; i++) {
        int comma = line.find(':', last_pos);
        int ed = line.find(',', last_pos);
        if (comma == string::npos) break;
        key = line.substr(last_pos, comma - last_pos);
        if (ed == string::npos) {
            value = line.substr(comma + 1, (int)line.size() - 2 - comma);
        } else {
            value = line.substr(comma + 1, ed - 1 - comma);
            last_pos = ed + 1;
        }
            
        dict[key] = value;
        if (ed == string::npos) break;
        
    }
}

int main() {
    
    map<string, string> old_dict, new_dict;
    cin >> T;
    string line;
    getline(cin, line);
    while (T--) {
        old_dict.clear(); new_dict.clear();
        getline(cin, line);
        parse(line, old_dict);
        
        getline(cin, line);
        parse(line, new_dict);
        
        vector<string> plus, minus, change;
        for (map<string, string>::const_iterator cit = new_dict.begin(); cit != new_dict.end(); cit++) {
            const string& new_key = cit->first;
            const string& new_val = cit->second;
            if (!old_dict.count(new_key)) plus.push_back(new_key);
            else if (old_dict[new_key] != new_val) change.push_back(new_key);
        }
        
        for (map<string, string>::const_iterator cit = old_dict.begin(); cit != old_dict.end(); cit++) {
            const string& old_key = cit->first;
            const string& old_val = cit->second;
            if (!new_dict.count(old_key)) minus.push_back(old_key);
        }
        
        stringstream ss;
        for (int i = 0; i < plus.size(); i++) {
            if (!i) ss << "+" << plus[i];
            else ss << "," << plus[i];
        }
        if (plus.size()) ss << endl;
        for (int i = 0; i < minus.size(); i++) {
            if (!i) ss << "-" << minus[i];
            else ss << "," << minus[i];
        }
        if (minus.size()) ss << endl;
        for (int i = 0; i < change.size(); i++) {
            if (!i) ss << "*" << change[i];
            else ss << "," << change[i];
        }
        if (change.size()) ss << endl;
        string output = ss.str();
        if (output.empty()) puts("No changes");
        else cout << output;
        cout << endl;
    }
    
  
    return 0;
}