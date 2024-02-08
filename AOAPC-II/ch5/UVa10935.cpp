// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 52;
int n;

template <typename T>
ostream& operator << (ostream& os, vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << ' ';
    }
    return os;
}

int main() {
    int cards[N << 3];
    while (cin >> n && n) {
        memset(cards, 0, sizeof(cards));
        for (int i = 1; i <= n; i++) 
            cards[i] = i;
        int l = 1, r = n;
        printf("Discarded cards:");
        while (1) {
            if (l == r) break;
            printf(" %d", cards[l]);
            l++;
            if (l != r) printf(",");
            cards[++r] = cards[l++];
        }
        puts("");
        printf("Remaining card: %d\n", cards[r]);
    }
  
    return 0;
}