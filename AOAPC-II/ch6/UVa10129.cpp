// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 3;
char w[N];
int deg[26], seen[26];
int fa[26];

int find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  int T;
  cin >> T;
  while (T--) {
    memset(deg, 0, sizeof(deg));
    memset(seen, 0, sizeof(seen));
    for (int i = 0; i < 26; i++) fa[i] = i;
    int n; 
    cin >> n;
    int tot = 26;
    for (int i = 0; i < n; i++) {
      scanf("%s", w);
      int c1 = w[0] - 'a', c2 = w[strlen(w) - 1] - 'a';
      deg[c1]++; deg[c2]--;
      seen[c1] = seen[c2] = 1;
      int fc1 = find(c1), fc2 = find(c2);
      if (fc1 != fc2) {
        fa[fc1] = fc2;
        tot--;
      }
    }
    for (int i = 0; i < 26; i++) if (!seen[i]) tot--;
    vector<int> judge;
    for (int i = 0; i < 26; i++) if (deg[i]) judge.push_back(deg[i]);
    
    if (tot == 1 && (judge.empty() || (judge.size() == 2 && (judge[0] == 1 || judge[0] == -1)))) 
      printf("Ordering is possible.\n");
    else printf("The door cannot be opened.\n");
  }
  
  
  return 0;
}