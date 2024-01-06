#include <bits/stdc++.h>

using namespace std;

int n, k;
char d[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void trans(int n, int k) {
    int r = n % k;
    n /= k;
    if (n > 0) trans(n, k);
    cout << d[r];
    
}

int main() {
    cin >> n >> k;
    trans(n, k);
    cout << endl;
    
    return 0;
}

