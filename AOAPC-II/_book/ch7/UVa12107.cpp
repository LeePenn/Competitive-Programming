// Joker
#include <bits/stdc++.h>
using namespace std;

struct Exp {
  string A[3];
  bool operator < (const Exp& rhs) const {
    for (int i = 0; i < 3; i++) {
      if (A[i] != rhs.A[i]) return A[i] < rhs.A[i];
    }
    return false;
  }
};

map<Exp, int> SolCnt;

void dfs_gen(Exp& e, int cur, int pos) {
  if (cur >= 3) return;
  int nCur = cur + (pos + 1) / e.A[cur].size(), nPos = (pos + 1) % e.A[cur].size();
  dfs_gen(e, nCur, nPos);
  
  auto bk = e.A[cur][pos];
  e.A[cur][pos] = '*';
  SolCnt[e]++;
  dfs_gen(e, nCur, nPos);
  e.A[cur][pos] = bk;
}

void generate() {
  Exp e;
  for (int a = 1; a < 100; a++) {
    for (int b = 1; b < 100; b++) {
      e.A[0] = to_string(a), e.A[1] = to_string(b), e.A[2] = to_string(a * b);
      dfs_gen(e, 0, 0);
    }
  }
}

const string CH = "*0123456789";
int maxd;

void dfs(int d, int cur, int pos, bool& found, Exp& cur_e, Exp& ans) {
  
  if (found && ans < cur_e) return; // 注释掉也可以，但是是剪枝，应该会快点
  if (d > maxd) return;
  if (SolCnt.count(cur_e) && SolCnt[cur_e] == 1) {
    if (!found) { found = true; ans = cur_e; }
    if (cur_e < ans) ans = cur_e;
    return;
  }
  if (cur >= 3) return;
  
  
  int nCur = cur + (pos + 1) / cur_e.A[cur].size(), nPos = (pos + 1) % cur_e.A[cur].size();
  auto bk = cur_e.A[cur][pos];
  for (int i = 0; i < CH.size(); i++) {
    if (CH[i] == '0' && pos == 0) continue;
    cur_e.A[cur][pos] = CH[i];
    int nd = d + (bk != CH[i]);
    dfs(nd, nCur, nPos, found, cur_e, ans);
    cur_e.A[cur][pos] = bk;
  }
  
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  generate();
  //for (map<Exp, int>::const_iterator cit = SolCnt.begin(); cit != SolCnt.end(); cit++) {
    //cout << (*cit).first.A[0] << ' ' << (*cit).first.A[1] << ' ' << (*cit).first.A[2] << endl;
  //}
  
  Exp e;
  for (int kase = 1; cin >> e.A[0] && e.A[0] != "0"; kase++) {
    cin >> e.A[1] >> e.A[2];
    cout << "Case " << kase << ": ";
    for (maxd = 0; maxd <= 8; maxd++) {
      Exp cur_e = e, ans;
      bool found = false;
      dfs(0, 0, 0, found, cur_e, ans);
      if (found) {
        cout << ans.A[0] << ' ' << ans.A[1] << ' ' << ans.A[2] << endl;
        break;
      }
    }
  }
  
  
  return 0;
}