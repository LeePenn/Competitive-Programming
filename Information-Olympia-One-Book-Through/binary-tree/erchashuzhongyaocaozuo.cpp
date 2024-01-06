#include <bits/stdc++.h>

using namespace std;

typedef struct node node;
typedef node* tree;

struct node {
    char data;
    tree lchild, rchild;
};
tree bt;

void build(tree &bt) {
    char c = getchar();
    if (c != '$') {
        bt = new node();
        bt->data = c;
        build(bt->lchild);
        build(bt->rchild);
    } else {
        bt = NULL;
    }
}

void dis(tree &bt) {
    if (bt) {
        dis(bt->lchild);
        dis(bt->rchild);
        delete bt;
    }
}

void insert(tree &bt, int n) {
    if (bt) {
        if (bt->data > n) insert(bt->lchild, n);
        else if (bt->data < n) insert(bt->rchild, n);
    } else {
        bt = new node();
        bt->data = n;
        bt->lchild = bt->rchild = NULL;
    }
} 

tree searchn(tree bt, int n) {
    if (bt) {
        if (bt->data == n) return bt;
        if (bt->data > n) return searchn(bt->rchild, n);
        else if (bt->data < n) return searchn(bt->lchild, n);
    } else {
        return NULL;
    }
}

void print(tree bt) {
    if (bt) {
        cout << bt->data;
        if (bt->lchild || bt->rchild) {
            cout << '(';
            print(bt->lchild);
            if (bt->rchild) cout << ',';
            print(bt->rchild);
            cout << ')';
        }
    }
}

int main() {


    return 0;
}