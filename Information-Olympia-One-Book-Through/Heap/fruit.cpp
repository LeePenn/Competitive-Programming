#include <bits/stdc++.h>

using namespace std;

int n, x, heap[100000], heap_size;

void put(int x) {
    heap[++heap_size] = x;
    int son = heap_size;
    while (son >= 1) {
        int pa = son >> 1;
        if (heap[pa] <= heap[son]) break;
        swap(heap[pa], heap[son]);
        son = pa;
    }
}

int get() {
    int ret = heap[1];
    heap[1] = heap[heap_size--];
    int pa = 1, son;
    while ((pa << 1) <= heap_size) {
        son = pa << 1;
        if (son < heap_size && heap[son + 1] <= heap[son]) son++;
        if (heap[son] >= heap[pa]) break;
        swap(heap[son], heap[pa]);
        pa = son;
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    heap_size = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        put(x);
    }
    
    int ans = 0;
    while (heap_size > 1) {
        int t1 = get(), t2 = get();
        ans += t1 + t2;
        put(t1 + t2);
    }
    cout << ans << endl;

    return 0;
}