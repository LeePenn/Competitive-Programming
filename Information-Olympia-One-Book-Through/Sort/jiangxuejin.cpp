#include <bits/stdc++.h>

using namespace std;

struct student {
    int id, chinese, math, english;
    int total;
} stu[10000];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        stu[i].id = i;
        scanf("%d%d%d", &stu[i].chinese, &stu[i].math, &stu[i].english);
        stu[i].total = stu[i].chinese + stu[i].math + stu[i].english;
    }
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            if (stu[j].total < stu[j + 1].total || (stu[j].total == stu[j + 1].total && stu[j].chinese < stu[j + 1].chinese) || (stu[j].total == stu[j + 1].total && stu[j].chinese == stu[j + 1].chinese && stu[j].id > stu[j + 1].id)) {
                swap(stu[j], stu[j + 1]);
            }
        }
    }
    for (int i = 1; i <= 5; i++) {
        printf("%d %d\n", stu[i].id, stu[i].total);
    }

    return 0;
}