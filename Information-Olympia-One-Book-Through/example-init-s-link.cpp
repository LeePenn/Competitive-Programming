#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *nxt;
};
Node *head, *p, *r;
int x;

int main() {
    cin >> x;
    head = new Node;
    r = head;
    while (x != -1) {
        p = new Node;
        p->data = x;
        p->nxt = NULL;
        r->nxt = p;
        r = p;
        cin >> x;
    }
    p = head->nxt;
    while (p->nxt != NULL) {
        cout << p->data << " ";
        p = p->nxt;
    }
    cout << p->data << endl;
    system("pause");



}