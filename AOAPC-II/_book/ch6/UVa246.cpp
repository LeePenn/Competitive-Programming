// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 52;
int readint() { int x; cin >> x; return x; }

deque<int> cards;
deque<int> allPiles[7];
list<deque<int>* > piles;
unordered_set<string> phases;

void encode(string& s) {
  s.clear();
  for (auto& pp : piles) {
    deque<int>& p = *pp;
    for (auto c : p) s += (char)c;
    s += '|';
  }
  for (auto c : cards) {
    s += (char)c;
  }
  return;
}

void procPile(deque<int>& p) {
  int n = p.size();
  if(n < 3) return;
  if ((p[0] + p[1] + p.back()) % 10 == 0) {
      cards.push_back(p[0]), cards.push_back(p[1]), cards.push_back(p.back());
      p.pop_front(), p.pop_front(), p.pop_back();
      procPile(p);
      return;
  } 

  if ((p[0] + p[n-2] + p[n-1]) % 10 == 0) {
      cards.push_back(p[0]), cards.push_back(p[n-2]), cards.push_back(p[n-1]);
      p.pop_front(), p.pop_back(), p.pop_back();
      procPile(p);
      return;
  } 
  
  if ((p[n-3] + p[n-2] + p[n-1]) % 10 == 0) {
      cards.push_back(p[n-3]), cards.push_back(p[n-2]), cards.push_back(p[n-1]);
      p.pop_back(), p.pop_back(), p.pop_back();
      procPile(p);
      return;
  }
}

bool simulate(int turn) {
  if (piles.empty()) {
    cout << "Win : " << turn << endl;
    return false;
  }
  
  if (cards.empty()) {
    cout << "Loss: " << turn << endl;
    return false;
  }
  
  string pha;
  encode(pha);
  if (phases.count(pha)) {
    cout << "Draw: " << turn << endl;
    return false;
  }
  
  phases.insert(pha);
  
  int c = cards.front();
  cards.pop_front();
  piles.push_back(piles.front());
  piles.pop_front();
  
  deque<int>& p = *(piles.back());
  p.push_back(c);
  procPile(p);
  if(p.empty()) piles.pop_back();
  
  return true;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (1) {
    cards.clear(), piles.clear(), phases.clear();
    for (int i = 0; i < N; i++) {
      int c = readint();
      if(c == 0) return 0;
      cards.push_back(c);
    }
    
    for (int i = 0; i < 7; i++) {
      deque<int>& p = allPiles[i];
      p.clear();
      p.push_back(cards.front());
      cards.pop_front();
      piles.push_back(&p);
    }
    
    int t = 7;
    while (1) if (!simulate(t++)) break;
  }
  
  
  return 0;
}