// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 1003, W = 8, IPW = W * 4;
int n, ip[4], ips[N][IPW + 2];

template<typename T>
ostream& operator << (ostream& os, vector<T>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (i) os << ' ';
        os << v[i];
    }
    return os;
}

void toBinary(int ip, int* v, int pos) {
    for (int i = 0; i < W; i++) {
        v[pos + W - i - 1] = ip & 1;
        ip >>= 1;
    }
}

void printIP(int* v) {
    bool first = true;
    for (int i = 0; i < 4; i++) {
        int x = 0;
        for (int j = i * W; j < (i + 1) * W; j++) {
            x = (x << 1) + v[j];
        }
        if (first) first = false;
        else printf(".");
        printf("%d", x);
    }
    puts("");
}

int main() {
    int subNet[IPW];
    while (scanf("%d", &n) == 1 && n) {
        memset(subNet, 0, sizeof(subNet));
        for (int i = 0; i < n; i++) {
            scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
            for (int j = 0; j < 4; j++)
                toBinary(ip[j], ips[i], j * W);
            
        }
        int m;
        for (m = 0; m < IPW; m++) {
            bool same = true;
            for (int i = 1; i < n; i++) {
                if (ips[i][m] != ips[i - 1][m]) {
                    same = false;
                    break;
                }
            }
            if (!same) break;
        }
        fill_n(subNet, m, 1);
        fill_n(ips[0] + m, IPW - m, 0);
        printIP(ips[0]);
        printIP(subNet);
    }
    return 0;
}