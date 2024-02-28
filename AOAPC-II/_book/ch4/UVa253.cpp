// Joker
#include <bits/stdc++.h>
using namespace std;
template<typename T>
ostream& operator << (ostream& os, vector<T>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (i) os << ' ';
        os << v[i];
    }
    return os;
}
int ROT[24][7] = {
{0,1,2,3,4,5,6},
{0,1,3,5,2,4,6},
{0,1,4,2,5,3,6},
{0,1,5,4,3,2,6},
{0,2,1,4,3,6,5},
{0,2,3,1,6,4,5},
{0,2,4,6,1,3,5},
{0,2,6,3,4,1,5},
{0,3,1,2,5,6,4},
{0,3,2,6,1,5,4},
{0,3,5,1,6,2,4},
{0,3,6,5,2,1,4},
{0,4,1,5,2,6,3},
{0,4,2,1,6,5,3},
{0,4,5,6,1,2,3},
{0,4,6,2,5,1,3},
{0,5,1,3,4,6,2},
{0,5,3,6,1,4,2},
{0,5,4,1,6,3,2},
{0,5,6,4,3,1,2},
{0,6,2,4,3,5,1},
{0,6,3,2,5,4,1},
{0,6,4,5,2,3,1},
{0,6,5,3,4,2,1},
};

int main() {
    char str[15];
    while (scanf("%s", str) == 1) {
        string s1 = "", s2 = "";
        for (int i = 0; i < 12; i++) {
            if (i < 6) s1 += str[i];
            else s2 += str[i];
        }
        
        bool same = false;
        for (int i = 0; i < 24; i++) {
            string t = "";
            for (int j = 1; j <= 6; j++) {
                t += s1[ROT[i][j] - 1];
            }
            if (t == s2) {
                same = true;
                break;
            }
        }
        
        if (!same) puts("FALSE");
        else puts("TRUE");
    }
    return 0;
}