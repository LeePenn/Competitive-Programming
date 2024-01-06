#include <bits/stdc++.h>

using namespace std;

bool chosen[23], prime[45];
int ans[23];

bool isprime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;

}

bool work(int cnt) {
    if (cnt == 20) {
        if (prime[ans[20] + ans[1]]) return true;
        return false;
    }

    for (int i = 2; i <= 20; i++) {
        if (chosen[i]) continue;
        if (prime[i + ans[cnt]]) {
            cnt++;
            chosen[i] = true;
            ans[cnt] = i;
            if (work(cnt)) {
                return true;
            }
            cnt--;
            chosen[i] = false;
        }
    
    }
    return false;
}

int main() {
    memset(chosen, 0, sizeof(0));
    memset(prime, true, sizeof(prime));
    for (int i = 2; i <= 40; i++) {
        if (!isprime(i)) prime[i] = false;
    }
    
    ans[1] = 1;
    chosen[1] = true;
    if (work(1)) {
        for (int i = 1; i <= 20; i++) printf("%d ", ans[i]);
        cout << endl;
    }

    return 0;
}