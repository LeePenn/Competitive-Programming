#include <bits/stdc++.h>

using namespace std;

string s;
int t, k;

int main() {
    cin >> t;
    while (t--) {
        cin >> s >> k;
        int m = s.size();
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < m - 1; j++) {
                if (s[j] > s[j + 1]) {
                    for (int p = j; p < m - 1; p++) {
                        s[p] = s[p + 1];
                    }
                    break;
                }
            }
            m--;
        }
        
        for (int i = 0; i < m; i++) cout << s[i];
        cout << endl;
    }
    
    

    return 0;
}