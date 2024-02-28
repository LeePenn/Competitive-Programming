#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 1000 + 5;

struct Lamp {
    int v, k, c, l;
    bool operator <(const Lamp &rhs) const {
        return v < rhs.v;
    }
}lamp[MAXN];

int n, s[MAXN], dp[MAXN];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    while (cin >> n && n) {
        for (int i = 1; i <= n; ++i) {
            cin >> lamp[i].v >> lamp[i].k >> lamp[i].c >> lamp[i].l;
            
        }
        sort(lamp + 1, lamp + n + 1);
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i - 1] + lamp[i].l;
        }
        
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = s[i] * lamp[i].c + lamp[i].k;
            for (int j = i; j >= 1; --j) {
                dp[i] = min(dp[i], dp[j] + (s[i] - s[j]) * lamp[i].c + lamp[i].k);
            }
        }
        
        cout << dp[n] << endl;
    }
    


    return 0;
}