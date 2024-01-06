#include <bits/stdc++.h>

using namespace std;

int n, a[1000], s[1000];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int i = 1;
    int top = 0;
    int p = 1;
    while (p <= n) {
        s[++top] = p;
        p++;
        if (s[top] == i) {
            top--;
            i++;
        }
    }
    if (top == 0) printf("YES\n");
    else printf("NO\n");

    return 0;
}