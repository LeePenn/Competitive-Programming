// Joker
#include <bits/stdc++.h>
using namespace std;

void parse_address(const string& s, string& user, string& mta) {
    int k = s.find('@');
    user = s.substr(0, k);
    mta = s.substr(k + 1);
}

int main() {
    set<string> addr;
    int n;
    string s, t, user1, mta1, user2, mta2;
    while (cin >> s && s != "*") {
        cin >> s >> n;
        for (int i = 0; i < n; i++) {
            cin >> t;
            addr.insert(t + '@' + s);
        }
    }
    while (cin >> s && s != "*") {
        parse_address(s, user1, mta1);
        
        
        vector<string> mta;
        map<string, vector<string> > dest;
        set<string> vis;
        while (cin >> t && t != "*") {
            if (vis.count(t)) continue;
            vis.insert(t);
            parse_address(t, user2, mta2); 
            if (!dest.count(mta2)) {
                mta.push_back(mta2);
                dest[mta2] = vector<string>();
            }
            dest[mta2].push_back(t);
            
        }
        getline(cin, t);
        
        string data;
        while (getline(cin, t) && t[0] != '*') data += "     " + t + "\n";
        for (int i = 0; i < mta.size(); i++) {
            cout << "Connection between " << mta1 << " and " << mta[i] << "\n";
            cout << "     HELO " << mta1 << "\n";
            cout << "     250\n";
            cout << "     MAIL FROM:<" << s << ">\n";
            cout << "     250\n";
            vector<string> users = dest[mta[i]];
            bool ok = false;
            for (int j = 0; j < users.size(); j++) {
                cout << "     RCPT TO:<" << users[j] << ">\n";
                if (addr.count(users[j])) {
                    ok = true;
                    cout << "     250\n";
                } else cout << "     550\n";
            }
            if (ok) {
                cout << "     DATA\n";
                cout << "     354\n";
                cout << data;
                cout << "     .\n";
                cout << "     250\n";
            }
            cout << "     QUIT\n";
            cout << "     221\n";
        }
    }
    
    return 0;
}