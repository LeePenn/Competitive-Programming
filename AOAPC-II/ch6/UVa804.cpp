// Joker
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> tokens;
struct Trans {
  unordered_map<int, int> input;
  vector<int> output;
  bool enabled() const {
    for (const auto& p : input) {
      if (tokens[p.first] < p.second) return false;
    }
    return true;
  }
  void fire() const {
    for (const auto& p : input) {
      tokens[p.first] -= p.second;
    }
    for (int i = 0; i < output.size(); i++) {
      tokens[output[i]]++;
    }
  }
};

vector<Trans> TS;
int enabledTrans() {
  for (int i = 0; i < TS.size(); i++) {
    if (TS[i].enabled()) return i;
  }
  return -1;
}
int NP, NT, NF;

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  for (int kase = 1; scanf("%d", &NP) == 1 && NP; kase++) {
    tokens.resize(NP);
    for (int i = 0; i < NP; i++) {
      scanf("%d", &tokens[i]);
    }
    scanf("%d", &NT);
    TS.clear(); TS.resize(NT);
    for (int i = 0; i < NT; i++) {
      int x;
      auto& t = TS[i];
      while (scanf("%d", &x) && x != 0) {
        if (x < 0) {
          t.input[-x - 1]++;
        } else {
          t.output.push_back(x - 1);
        }
      }
    }
    scanf("%d", &NF);
    int cnt = 0, live = 1;
    for (int i = 0; i < NF; i++) {
      int ti = enabledTrans(); 
      if (ti == -1) {
        live = 0;
        break;
      }
      cnt++;
      TS[ti].fire();
    }
    printf("Case %d: ", kase);
    if (live) 
      printf("still live after %d transitions\n", NF);
    else 
      printf("dead after %d transitions\n", cnt);
    printf("Places with tokens:");
    for (int i = 0; i < NP; i++) {
      if (tokens[i]) printf(" %d (%d)", i + 1, tokens[i]);
    }
    printf("\n\n");
  }
  
  return 0;
}