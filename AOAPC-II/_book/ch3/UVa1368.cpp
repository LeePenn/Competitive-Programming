// Joker
#include <bits/stdc++.h>
using namespace std;
string line;
vector<string> str;
int t, n, m;
int cnt[256];

int main() {
    cin >> t;
    while (t--) {
        str.clear();
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> line;
            str.push_back(line);
        }
        int ans = 0;
        string ans_str = "";
        for (int j = 0; j < m; j++) {
            char c, mxcnt = 0;
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < n; i++) {
                //cout << str[i][j] << ' ';
                ++cnt[str[i][j]];
                if (cnt[str[i][j]] > mxcnt || (cnt[str[i][j]] == mxcnt && str[i][j] < c)) {
                    mxcnt = cnt[str[i][j]];
                    c = str[i][j];
                }
            }
            //cout << endl;
            ans_str += c;
            ans += n - mxcnt;
        }
        printf("%s\n", ans_str.c_str());
        cout << ans << endl;
    }
    return 0;
}