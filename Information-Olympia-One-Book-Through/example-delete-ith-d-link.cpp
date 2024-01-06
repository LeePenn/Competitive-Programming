#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *pre, *nxt;
};
node *p;

void del(node *head, int i) {
    int j = 0;
    p = head;
    while (p->nxt != NULL && j < i) {
        p = p->nxt;
        j++;
    }
    if (p == NULL) {
        cout << "no this position!" << endl;
    } else {
        p->pre->nxt = p->nxt;
        p->nxt->pre = p->pre;
        free(p);
    }
}

int main() {


    return 0;
}