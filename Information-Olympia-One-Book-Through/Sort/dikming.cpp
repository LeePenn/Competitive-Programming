#include <bits/stdc++.h>

using namespace std;

string name[10000];
double score[10000];
int n, k;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        cin >> name[i] >> score[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            if (score[j + 1] > score[j]) {
                swap(score[j + 1], score[j]);
                swap(name[j + 1], name[j]);
            }
        }
    }
    printf("%s %g\n", name[k].c_str(), score[k]);
    
    return 0;
}