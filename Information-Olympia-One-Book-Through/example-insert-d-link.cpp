#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node *pre, *nxt;
};
node *head, *p, *q, *r;

void insert(node *head, int i, int x) {
    node *s, *p;
    s = new node();
    s->data = x;
    p = head;
    int j = 0;
    while ((p->nxt != NULL) && (j < i)) {
        p = p->nxt;
        j++;
    }
    if (p == NULL) {
        cout << "no this position!" << endl;
    } else {
        s->pre = p->pre;
        p->pre->nxt = s;
        s->nxt = p;
        p->pre = s;
    }

}

int main() {

    node *head = new node();
    head->data = 10000;
    node *head_nxt = new node();
    head_nxt->data = 100;
    head->nxt = head_nxt;
    head_nxt->pre = head;
    for (int i = 0; i < 1; i++) {
        insert(head, 1, i + 1);
    }

    p = head;
    while (p != NULL) {
        cout << p->data << ' ';
        p = p->nxt;
    }
    cout << endl;

    p = head->nxt->nxt;
    while (p != NULL) {
        cout << p->data << ' ';
        p = p->pre;
    }
    cout << endl;

    return 0;
}