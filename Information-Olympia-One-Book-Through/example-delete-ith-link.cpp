#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *nxt;
};

void del(Node *head, int i) {
    Node *p;
    int j = 0;
    p = head;
    while (p->nxt != NULL && j < i - 1) {
        p = p->nxt;
        j++;
    }
    if (p->nxt == NULL) {
        cout << "no this position!" << endl;
    } else {
        Node *s = new Node;
        s = p->nxt;
        p->nxt = p->nxt->nxt;
        free(s);
    }
}

int main() {




    return 0;
}