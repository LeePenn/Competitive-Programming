#include <bits/stdc++.h>

using namespace std;

int a[10005], n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        int minx = a[i];
        int mini = i;
        for (int j = i; j <= n; j++) {
            if (a[j] <= minx) {
                mini = j;
                minx = a[j];
            }
        }
        int tmp = a[i];
        a[i] = a[mini];
        a[mini] = tmp;
    }
    
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;


    return 0;
}