// Joker
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> h;
double w;

int main() {
    int id = 0;
    while (cin >> n >> m && n && m) {
        h.clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int x;
                scanf("%d", &x);
                h.push_back(x);
            }
        }
        h.push_back(INT_MAX);
        scanf("%lf", &w);
        w /= 100;
        sort(h.begin(), h.end());
        int k;
        double cover = 0;
        for (int i = 1; i <= n * m; i++) {
            w += h[i - 1];
            cover = w / i;
            if (cover < h[i]) {
                k = i;
                break;
            }
        }
        printf("Region %d\n", ++id);
        printf("Water level is %.2lf meters.\n", cover);
        printf("%.2lf percent of the region is under water.\n\n", (double)k * 100 / (n * m));
    }
    
    return 0;
}