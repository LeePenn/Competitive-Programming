#include <bits/stdc++.h>

using namespace std;

typedef struct node node;
typedef node* tree;
// or write like below
// typedef struct node* tree;

struct node {
    char data;
    tree lchild, rchild;
};
tree bt;
string s;
int p;

void build(tree &bt) {
    if (s[++p] != '.') {
        bt = new node();
        bt->data = s[p];
        build(bt->lchild);
        build(bt->rchild);
    } else {
        bt = NULL;    
    }
}

void printzx(tree &bt) {
    if (bt) {
        printzx(bt->lchild);
        cout << bt->data;
        printzx(bt->rchild);
    }
}

void printhx(tree &bt) {
    if (bt) {
        printhx(bt->lchild);
        printhx(bt->rchild);
        cout << bt->data;
    }
}

int main() {
    cin >> s;
    p = -1;
    build(bt);
    printzx(bt);
    cout << endl;
    printhx(bt);
    cout << endl;
    
    return 0;
}