// Joker
#include <bits/stdc++.h>
using namespace std;
int T, n, m;
struct Job {
    int p, id;
    Job(int p = 0, int id = -1):p(p), id(id) {}
    bool operator < (const Job& o) const {
        return p < o.p;
    }
};

template <typename T>
ostream& operator << (ostream& os, vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << ' ';
    }
    return os;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> m;
        queue<Job> q;
        priority_queue<Job> heap;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            Job j(x, i);
            q.push(j);
            heap.push(j);
        }
        int ans = 0;
        set<int> finish;
        while (1) {
            Job cur = q.front(); q.pop();
            while (finish.count(heap.top().id)) heap.pop();
            if (cur.p == heap.top().p) {
                finish.insert(cur.id);
                ans++;
                if (cur.id == m) break;
            } else {
                assert(cur.p < heap.top().p);
                q.push(cur);
            }
        }
        printf("%d\n", ans);
    }
    
    
    
  
    return 0;
}