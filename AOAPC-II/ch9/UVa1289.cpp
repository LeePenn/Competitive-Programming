#include <bitset>
#include <cassert>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#define N 10005
#define INF 1047483647
#define MOD 1000000007
using namespace std;
int n,t,cnt,tot[2501],f[2501][51],s[51][51];
set<int> G[2501];
bool color[51][2501];
int main()
{
    while(~scanf("%d",&n))
    {
        cnt = 0;
        memset(f,0x3f,sizeof(f));
        memset(color,0,sizeof(color));
        for(int i = 1;i <= 2500;i++) G[i].clear();
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&s[i][0]);
            for(int j = 1;j <= s[i][0];j++)
            {
                scanf("%d",&s[i][j]);
                tot[++cnt] = s[i][j];
            }
            s[i][0] = unique(s[i]+1,s[i]+1+s[i][0]) - (s[i] + 1);
        }
        sort(tot+1,tot+1+cnt);
        cnt = unique(tot+1,tot+1+cnt) - (tot + 1);
        for(int i = 1;i <= n;i++)
         for(int j = 1;j <= s[i][0];j++)
         {
             s[i][j] = lower_bound(tot+1,tot+1+cnt,s[i][j]) - tot;
             G[s[i][j]].insert(i);
             color[i][s[i][j]] = 1;
         }
        for(int i : G[1]) f[1][i] = G[1].size()-1;
        for(int i = 2;i <= cnt;i++)
         for(int j : G[i])
          for(int k : G[i-1])
           if(j != k) f[i][j] = min(f[i][j],(f[i-1][k] + int(G[i].size()) - (color[k][i]? 1 : 0)));
           else f[i][j] = min(f[i][j],(G[i].size() == 1)? f[i-1][j] : INF);
        int ans = INF;
        for(int i = 1;i <= n;i++) ans = min(ans,f[cnt][i]);
        cout<<"Case "<<++t<<": "<<ans*2-n+1<<endl;
    }
}