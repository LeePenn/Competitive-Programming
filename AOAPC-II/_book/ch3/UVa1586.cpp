// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 102;
int n;
char s[N];

double get(char c) {
    switch (c) {
        case 'C':
            return 12.01;
        case 'H':
            return 1.008;
        case 'O':
            return 16;
        default:
            return 14.01;
    }
}

int main() {
    cin >> n;
    while (n--) {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        double ans = 0;
        for (int i = 1; i <= len; i++) {
            char cur = s[i];
            if (i + 1 > len || (i + 1 <= len && isalpha(s[i + 1]))) {
                ans += get(cur);
            } else {
                int cnt = 0, j = i;
                while (j + 1 <= len && isdigit(s[j + 1])) {
                    cnt = cnt * 10 + (s[j + 1] - '0');
                    j++;
                }
                ans += get(cur) * cnt;
                i = j;
            }
        }
        printf("%.3f\n", ans);
    }
    return 0;
}