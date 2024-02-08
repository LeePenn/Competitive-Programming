// Joker
#include <bits/stdc++.h>
using namespace std;
int T, n;

template <typename T>
ostream& operator << (ostream& os, vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << ' ';
    }
    return os;
}

int main() {
    cin >> T;
    vector<int> seq, zero_seq;
    set<vector<int> > seen;
    while (T--) {
        
        cin >> n;
        seq.clear();
        zero_seq.resize(n);
        seen.clear();
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            seq.push_back(x);
        }
        seen.insert(seq);
        while (1) {
            int st = seq[0];
            for (int i = 0; i < n; i++) {
                if (i == n - 1) seq[i] = abs(seq[i] - st);
                else seq[i] = abs(seq[i + 1] - seq[i]);
            }
            if (seq == zero_seq) {
                puts("ZERO");
                break;
            }
            if (seen.count(seq)) {
                puts("LOOP");
                break;
            }
            seen.insert(seq);
        }
    }
  
    return 0;
}