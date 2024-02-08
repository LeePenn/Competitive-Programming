// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 52;
struct Card {
  char suit, rank;
  Card(char r, char s):suit(s), rank(r) {}
  bool match(const Card& rhs) const {
    return suit == rhs.suit || rank == rhs.rank;
  }
};
struct Pile {
  stack<Card> cards;
  Pile *prev, *nxt;
  void init() {
    while (cards.size()) cards.pop();
    prev = nullptr; nxt = nullptr;
  }
};

Pile piles[N + 1];
void connect(Pile *p1, Pile *p2) {
  if (p1) p1->nxt = p2;
  if (p2) p2->prev = p1;
}

Pile *getLeft3(Pile *p) {
  for (int i = 0; i < 3; i++) {
    p = p->prev;
    if (!p) return nullptr;
  }
  return p;
}

Pile *head;

void solve() {
  Pile *from, *to, *cur;
  while (1) {
    cur = head->nxt;
    from = to = nullptr;
    while (cur) {
      Pile *l3 = getLeft3(cur);
      if (l3 && l3 != head) {
        if (l3->cards.top().match(cur->cards.top())) {
          from = cur; to = l3; break;
        }
      }
      
      Pile *l1 = cur->prev;
      if (l1 && l1 != head) {
        if (l1->cards.top().match(cur->cards.top())) {
          from = cur; to = l1; break;
        }
      }
      cur = cur->nxt;
    }
    
    if (!from) break;
    to->cards.push(from->cards.top());
    from->cards.pop();
    if (from->cards.empty()) {
      connect(from->prev, from->nxt);
    }
  }
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  string s;
  head = &(piles[0]);
  head->init();
  head->nxt = &(piles[1]);
  while (1) {
    for (int i = 1; i <= N; i++) {
      if (cin >> s && s.size() == 2) {
        Pile& cur = piles[i];
        cur.init();
        cur.prev = &(piles[i - 1]);
        if (i + 1 <= N) cur.nxt = &(piles[i + 1]);
        cur.cards.push(Card(s[0], s[1]));
      } else return 0;
    }
    solve();
    Pile *cur = head->nxt;
    vector<int> ans;
    while (cur) {
      ans.push_back(cur->cards.size());
      cur = cur->nxt;
    }
    cout << ans.size() << " pile" << (ans.size() > 1 ? "s" : "") << " remaining:";
    for (int i = 0; i < (int)ans.size(); i++) printf(" %d", ans[i]);
    printf("\n");
  }
  
  
  
  return 0;
}