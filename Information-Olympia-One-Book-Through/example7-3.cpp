#include <bits/stdc++.h>

using namespace std;

int n;

struct node {
    int data;
    int rank;
    int index;
} num[10001];

bool cmp1(node x, node y) {
    return x.data < y.data;
}

bool cmp2(node x, node y) {
    return x.index < y.index;
}

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i].data);
        num[i].index = i;
    }

    sort(num + 1, num + n + 1, cmp1);
    for (int i = 1; i <= n; i++) {
        num[i].rank = i;
    }
    sort(num + 1, num + n + 1, cmp2);
    for (int i = 1; i <= n; i++) {
        printf("%d ", num[i].rank);
    }
    printf("\n");

    return 0;
}