#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *nxt;
};

void get(Node *head, int i) {
    Node *p;
    int j = 1;
    p = head->nxt;
    while (p != NULL && j < i) {
        p = p->nxt;
        j++;
    }
    if (p != NULL && j == i) {
        cout << p->data << endl;
    } else {
        cout << "i not exists!" << endl;
    }
}

int main() {



    return 0;
}