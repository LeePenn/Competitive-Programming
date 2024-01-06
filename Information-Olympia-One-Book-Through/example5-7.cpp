#include <bits/stdc++.h>

using namespace std;

const int N = 100;
bool prime[N + 4];

int main() {

    for (int i = 1; i <= N; i++) prime[i] = true;

    for (int i = 2; i <= sqrt(N); i++) {
        if (prime[i]) {
            for (int j = 2; j <= N / i; j++) prime[j * i] = false;
        }
    }

    for (int i = 2, t = 0; i <= N; i++) {
        if (prime[i]) {
            cout << setw(5) << i;
            t++;
            if (t % 5 == 0) cout << endl;
        }
    }
    cout << endl;

    return 0;
}