#include <bits/stdc++.h>

using namespace std;

int n, Id, Num;
string s;
list<int> a[200001];
list<int>::iterator j;

int main() {
    cin >> n;
    while (n--) {
        cin >> s;
        if (s == "new") cin >> Id;
        if (s == "add") {
            cin >> Id >> Num;
            a[Id].push_back(Num);
        }
        if (s == "merge") {
            cin >> Id >> Num;
            a[Id].merge(a[Num]);
        }
        if (s == "unique") {
            cin >> Id;
            a[Id].sort();
            a[Id].unique();
        }
        if (s == "out") {
            cin >> Id;
            if (!a[Id].empty()) {
                a[Id].sort();
                for (j = a[Id].begin(); j != a[Id].end(); j++) {
                    printf("%d ", *j);
                }
                printf("\n");
            } else {
                printf("\n");
            }
        }
    }
    
    return 0;
}