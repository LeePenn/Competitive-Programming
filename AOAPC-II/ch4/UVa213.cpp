// Joker
#include <bits/stdc++.h>
using namespace std;
int c[8][1 << 8];

int readchar() {
    for (;;) {
        int cur = getchar();
        if (cur != '\n' && cur != '\r') return cur;
    }
}

int readcodes() {
    memset(c, 0, sizeof(c));
    c[1][0] = readchar();
    for (int len = 2; len < 8; len++) {
        for (int i = 0; i < (1 << len) - 1; i++) {
            int cur = getchar();
            if (cur == EOF) return 0;
            if (cur == '\n' || cur == '\r') return 1;
            c[len][i] = cur;
        }
    }
    return 1;
}

int readint(int x) {
    int ans = 0;
    while (x--) {
        ans = ans * 2 + readchar() - '0';
    }
    return ans;
}

int main() {
    while (readcodes()) {
        for (;;) {
            int len = readint(3);
            if (!len) break;
            for (;;) {
                int cur = readint(len);
                if (cur == (1 << len) - 1) break;
                putchar(c[len][cur]);
            }
        }
        puts("");
    }
    
    return 0;
}