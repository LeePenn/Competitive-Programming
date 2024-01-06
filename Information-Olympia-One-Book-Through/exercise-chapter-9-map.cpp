#include <bits/stdc++.h>

using namespace std;

map<int, int> m;
map<int, int>::iterator m_it;

int main() {
    int n;
    scanf("%d", &n);
    m[1000000000] = 1;
    for (int i = 0; i < n; i++) {
        bool f = false;
        int a, b, id, v;
        scanf("%d%d", &id, &v);
        m_it = m.upper_bound(v);
        if (m_it == m.end()) {
            f = true;
            m_it--;
        }
        a = m_it->first - v;
        b = m_it->second;
        if (m_it != m.begin() && !f) {
            m_it--;
            if (a > (v - m_it->first) || (a == (v - m_it->first) && (m_it->first < v))) b = m_it->second;
        }
        printf("%d %d\n", id, b);
        m_it = m.find(b);
        if (m_it == m.end() || m_it->second > id) m[v] = id;
        
    }
    
    
    return 0;
}