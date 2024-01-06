#include <bits/stdc++.h>

using namespace std;

int heap[10000];
int heap_size;

void put(int n) {
    heap[++heap_size] = n;
    int son = heap_size;
    while (son >= 1) {
        int pa = son >> 1;
        if (heap[pa] <= heap[son]) break;
        swap(heap[pa], heap[son]);
        son = pa;
    }
}

void put_stl(int n) {
    heap[++heap_size] = n;
    push_heap(heap + 1, heap + heap_size + 1, greater<int>());
}

int get() {
    swap(heap[1], heap[heap_size]);
    int ret = heap[heap_size];
    heap_size--;
    int pa = 1;
    while ((pa << 1) <= heap_size) {
        int son = pa << 1;
        if (son < heap_size && heap[son + 1] < heap[pa]) son++;
        if (heap[son] >= heap[pa]) break;
        swap(heap[son], heap[pa]);
        pa = son;
    }
    
    return ret;
}

int get_stl() {
    pop_heap(heap + 1, heap + heap_size + 1, greater<int>());
    return heap[heap_size--];
}

int main() {

    return 0;
}