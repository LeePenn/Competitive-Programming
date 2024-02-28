#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 5000 + 3;
char s1[N], s2[N];
int st1[26], st2[26], ed1[26], ed2[26];
int c[2][N], d[2][N];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int kase;
    scanf("%d", &kase);
    while (kase--) {
        scanf("%s%s", s1 + 1, s2 + 1);
        
        int m = strlen(s1 + 1), n = strlen(s2 + 1);
        for (int i = 1; i <= m; ++i) {
            s1[i] = s1[i] - 'A';
        }
        for (int i = 1; i <= n; ++i) {
            s2[i] = s2[i] - 'A';
        }
        
        memset(st1, 0x3f, sizeof(st1)); memset(st2, 0x3f, sizeof(st2));
        memset(ed1, 0, sizeof(ed1)); memset(ed2, 0, sizeof(ed2));
        for (int i = 1; i <= m; ++i) {
            st1[s1[i]] = min(st1[s1[i]], i);
            ed1[s1[i]] = i;
        }
        
        for (int i = 1; i <= n; ++i) {
            st2[s2[i]] = min(st2[s2[i]], i);
            ed2[s2[i]] = i;
        }
        
        // for (int i = 0; i < 26; ++i) printf("%d %d\n", st2[i], ed2[i]);
        // exit(0);
        int t = 0;
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (!i && !j) continue;
                
                int v1 = 0x3f3f3f3f, v2 = 0x3f3f3f3f;
                if (i) v1 = d[t ^ 1][j] + c[t ^ 1][j];
                if (j) v2 = d[t][j - 1] + c[t][j - 1];
                
                d[t][j] = min(v1, v2);
                
                if (i) {
                    c[t][j] = c[t ^ 1][j];
                    // <= j 说明在 if (j) 时就已经算进去了
                    if (st1[s1[i]] == i && st2[s1[i]] > j) c[t][j]++;
                    if (ed1[s1[i]] == i && ed2[s1[i]] <= j) c[t][j]--;
                } else if (j) {
                    c[t][j] = c[t][j - 1];
                    if (st2[s2[j]] == j) c[t][j]++;
                    if (ed2[s2[j]] == j && ed1[s2[j]] == 0) c[t][j]--;
                }
            }
            
            t ^= 1;
        }
        
        printf("%d\n", d[t ^ 1][n]);
    }
    


    return 0;
}