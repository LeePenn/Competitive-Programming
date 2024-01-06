#include <bits/stdc++.h>

using namespace std;

char s[10];
int a, sign;

int main() {
    cin >> a;
    if (a < 0) sign = -1;
    else sign = 1;

    sprintf(s, "%d", a);
    int len = strlen(s);
    for (int i = 0; i <= len / 2; i++) {
        swap(s[i], s[len - 1 - i]);
    }
    sscanf(s, "%d", &a);
    a *= sign;
    cout << a << endl;


    return 0;
}