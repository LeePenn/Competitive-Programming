// Joker
#include <bits/stdc++.h>
using namespace std;
int a, b;
map<int, int> pos;

void solve(int a, const int b, string& ans, int& r) {
    ans = ".";
    pos.clear();
    while (1) {
        a *= 10;
        int p = pos[a];
        if (p == 0) {
            pos[a] = ans.size(); 
        } else {
            r = ans.size() - p;
            if (r > 50) {
                ans.erase(p + 50);
                ans += "...";
            }
            ans.insert(p, "(");
            ans += ")";
            break;
        }
        int div = a / b, mod = a % b;
        ans += (char)(div + '0');
        if (!mod) {
            ans += "(0)";
            r = 1;
            break;
        }
        a = mod;
    }
}

int main() {
    while (cin >> a >> b) {
        string ans = ".(0)";
        int r = 1;
        if (a % b) solve(a % b, b, ans, r);
        printf("%d/%d = %d%s\n", a, b, a / b, ans.c_str());
        printf("   %d = number of digits in repeating cycle\n\n", r);
    }
    return 0;
}