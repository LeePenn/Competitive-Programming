#include <bits/stdc++.h>

using namespace std;

struct node {
    int d;
    node *nxt;
};

node *head, *tail, *p;
int n, m;

int main() {

    cin >> n >> m;

    head = new node();
    head->d = 1;
    head->nxt = NULL;
    tail = head;

    for (int i = 2; i <= n; i++) {
        p = new node();
        p->d = i;
        tail->nxt = p;
        tail = p;
    }

    tail->nxt = head;
    tail = head;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m - 2; j++) {
            tail = tail->nxt;
        }
        cout << tail->nxt->d << " ";
        tail->nxt = tail->nxt->nxt;
        tail = tail->nxt;
    }


    return 0;
}