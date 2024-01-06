#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *nxt;
};

void insert(Node *head, int i, int x) {
    Node *p;
    int j = 0;
    p = head;
    while (p != NULL && j < i - 1) {
        p = p->nxt;
        j++;
    }
    if (p == NULL) {
        cout << "no this position!" << endl;
    } else {
        Node *s = new Node;
        s->data = x;
        s->nxt = p->nxt;
        p->nxt = s;
    }
}

int main() {



    return 0;
}