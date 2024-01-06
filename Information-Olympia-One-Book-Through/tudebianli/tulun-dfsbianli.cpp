#include <bits/stdc++.h>

using namespace std;

int n, num[100];
bool v[100];

void dfs(int i) {
    v[i] = 1;
    for (int j = 1; j <= num[i]; j++) {
        if (!v[j]) {
            dfs(j);
        }
    }
}

int main() {
    memset(v, 0, sizeof(v));
    for (int i = 1; i <= n; i++) {
        if (!v[i]) dfs(i);
    }
    
    return 0;
}