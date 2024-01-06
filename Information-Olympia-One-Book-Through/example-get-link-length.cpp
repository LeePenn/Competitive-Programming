#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *nxt;
};

int len(Node *head) {
    int n = 0;
    Node *p;
    p = head;
    while (p != NULL) {
        p = p->nxt;
        n++;
    }
    return n;
}

int main() {



    return 0;
}