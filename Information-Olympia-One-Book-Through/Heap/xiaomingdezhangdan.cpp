#include <bits/stdc++.h>

using namespace std;

int n, m, x;
multiset<int> st;
multiset<int>::iterator it;

int main() {
    cin >> n;
    st.clear();
    for (int i = 1; i <= n; i++) {
        cin >> m;
        for (int j = 1; j <= m; j++) {
            cin >> x;
            st.insert(x);
        }
        cout << *st.begin() << ' ';
        st.erase(st.begin());
        cout << *(--st.end()) << endl;
        st.erase(--st.end());
    }

    return 0;
}