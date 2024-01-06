#include <bits/stdc++.h>

using namespace std;

int d[9][9] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 1, 1},
    {0, 0, 1, 1, 1, 1, 0, 1, 1},
    {0, 0, 1, 1, 0, 0, 1, 1, 1},
    {0, 0, 1, 0, 1, 1, 1, 0, 1},
    {0, 1, 1, 0, 1, 1, 1, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 0, 0, 1, 1, 0},
    {0, 1, 1, 1, 1, 0, 0, 0, 1}
};
int a[110], b[110];
bool s[9];

void print(int tail) {
    cout << char(a[tail] + 64);
    while (b[tail]) {
        tail = b[tail];
        cout << "--" << char(a[tail] + 64);
    }
    cout << endl;
}

int main() {
    memset(s, 0, sizeof(s));
    int head = 0, tail = 1;
    a[1] = 1;
    b[1] = 0;
    s[1] = true;
    do {
        head++;
        for (int i = 1; i <= 8; i++) {
            if (d[head][i] == 0 && !s[i]) {
                tail++;
                a[tail] = i, b[tail] = head, s[i] = true;
                if (i == 8) {
                    print(tail);head = tail;break;
                }
            }
        }
        
    } while(head < tail);
    
    return 0;
}