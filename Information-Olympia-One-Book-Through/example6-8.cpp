#include <bits/stdc++.h>

using namespace std;

const char ch[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
int n;

void turn(int n, int k) {
    int ret[20];
    int count = 0;
    if (n < 0) {
        printf("-");
        n = abs(n);
    }

    while (n) {
        ret[count++] = n % k;
        n /= k;
    }

    for (int i = count - 1; ~i; i--) {
        if (ret[i] < 10) printf("%d", ret[i]);
        else printf("%c", ch[ret[i] - 10]);
    }
    printf("\n");

}

int main() {

    scanf("%d", &n);
    turn(n, 2);
    turn(n, 8);
    turn(n, 16);

    return 0;
}