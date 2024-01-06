#include <bits/stdc++.h>

using namespace std;

const int N = 63;
char s1[N], s2[N], x[N];
int main() {

    scanf("%s%s", s1, s2);
    if (strlen(s1) < strlen(s2)) {
        strcpy(x, s1);
        strcpy(s1, s2);
        strcpy(s2, x);
    }
    strcpy(x, s1);
    if (strstr(strcat(s1, x), s2) == NULL) {
        printf("false\n");
    } else {
        printf("true\n");
    }

    return 0;
}