// Joker
#include <bits/stdc++.h>
using namespace std;
const int ugly[] = {2, 3, 5};
#define ll long long
set<ll> seen;
priority_queue<ll, vector<ll>, greater<ll> > heap;


int main() {
    seen.insert(1);
    heap.push(1);
    for (int i = 1; i <= 1500; i++) {
        ll cur = heap.top(); heap.pop();
        if (i == 1500) {
            printf("The 1500'th ugly number is %lld.\n", cur);
        }
        for (int j = 0; j < 3; j++) {
            ll nxt = cur * ugly[j];
            if (!seen.count(nxt)) {
                seen.insert(nxt);
                heap.push(nxt);
            }
        }
    }
    
    return 0;
}