#include <bits/stdc++.h>

using namespace std;

struct Node {
    int num;
    Node *pre, *nxt;
} *head, *tail, *p;

int n, m;

int main() {
    
    while (scanf("%d%d", &n, &m) && (n || m)) {
        head = new Node();
        head->num = 1;
        head->pre = head->nxt = NULL;
        tail = head;
        
        for (int i = 2; i <= n; i++) {
            p = new Node();
            p->num = i;
            p->pre = tail;
            p->nxt = NULL;
            tail->nxt = p;
            tail = p;
        }
        tail->nxt = head;
        head->pre = tail;
        
        p = head;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                p = p->nxt;
            }
            p->nxt->pre = p->pre;
            p->pre->nxt = p->nxt;
            p = p->nxt;
        }
        printf("%d\n", p->num);
    }
    
    return 0;
}