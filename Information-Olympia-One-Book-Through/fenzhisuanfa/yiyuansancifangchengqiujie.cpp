#include <bits/stdc++.h>

using namespace std;

double a, b, c, d;

double f(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

int main() {
    cin >> a >> b >> c >> d;
    
    double i;
    for (i = -100; i <= 100; i++) {
        double x1 = i, x2 = i + 1;
        if (f(x1) == 0) {
            printf("%.2lf ", x1);
        } else if (f(x1) * f(x2) < 0) {
            while (x2 - x1 >= 0.001) {
                double m = (x2 + x1) / 2;
                if (f(x1) * f(m) <= 0) {
                    x2 = m;
                } else {
                    x1 = m;
                }
            }
            printf("%.2lf", x1);
        }
    }
    printf("\n");
    return 0;
}