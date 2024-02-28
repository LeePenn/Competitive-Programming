// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 26;
vector<int> pile[N];
int n;

void find_pile(int a, int& p, int& h) {
    for (p = 0; p < n; p++) {
        for (h = 0; h < pile[p].size(); h++) {
            if (pile[p][h] == a) return;
        }
    }
}

void pile_clear(int p, int h) {
    for (int i = h + 1; i < pile[p].size(); i++) {
        int cur = pile[p][i];
        pile[cur].push_back(cur);
    }
    pile[p].resize(h + 1);
}

void move_pile(int p, int h, int pb) {
    for (int i = h; i < pile[p].size(); i++) {
        pile[pb].push_back(pile[p][i]);
    }
    pile[p].resize(h);
}

void print() {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        for (int j = 0; j < pile[i].size(); j++) {
            printf(" %d", pile[i][j]);
        }
        puts("");
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        pile[i].clear();
        pile[i].push_back(i);
    }
    char op1[6], op2[6];
    int a, b;
    while (scanf("%s", op1) == 1 && op1[0] != 'q') {
        scanf("%d %s %d", &a, op2, &b);
        int pa, pb, ha, hb;
        find_pile(a, pa, ha);
        find_pile(b, pb, hb);
        if (pa == pb) continue;
        if (op2[1] == 'n') pile_clear(pb, hb);
        if (op1[0] == 'm') pile_clear(pa, ha);
        move_pile(pa, ha, pb);
    }
    print();
    return 0;
}