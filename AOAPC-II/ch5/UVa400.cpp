// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 102, M = 60;
int n;
string file[N];

void print(const string& s, int len, char c) {
    printf("%s", s.c_str());
    for (int i = 0; i < len - s.length(); i++) {
        printf("%c", c);
    }
}

int main() {
    while (scanf("%d", &n) == 1 && n) {
        int mx_len = 0;
        for (int i = 0; i < n; i++) {
            cin >> file[i];
            mx_len = max(mx_len, (int)file[i].length());
        }
        int cols = (M - mx_len) / (mx_len + 2) + 1;
        int rows = (n - 1) / cols + 1;
        print("", M, '-');
        puts("");
        sort(file, file + n);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int idx = j * rows + i;
                if (idx < n) print(file[idx], j == cols - 1 ? mx_len : mx_len + 2, ' ');
                if (j == cols - 1) puts("");
            }
        }
    }
    
    return 0;
}