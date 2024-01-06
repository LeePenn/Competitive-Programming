#include <bits/stdc++.h>

using namespace std;

typedef struct node;
typedef node *tree;

struct node {
    char data;
    tree lchild, rchild;
};
tree bt;

void preorder(tree bt) {
    if (bt) {
        cout << bt->data;
        preorder(bt->lchild);
        preorder(bt->rchild);
    }
}

void inorder(tree bt) {
    if (bt) {
        inorder(bt->lchild);
        cout << bt->data;
        inorder(bt->rchild);
    }
}

void postorder(tree bt) {
    if (bt) {
        postorder(bt->lchild);
        postorder(bt->rchild);
        cout << bt->data;
    }
}

void preorderstack(tree bt) {
    tree stack[100];
    int top = -1;
    while (bt || top) {
        while (bt) {
            cout << bt->data;
            if (bt->rchild) {
                stack[++top] = bt->rchild;
            } 
            bt = bt->lchild;
        }
        if (top) {
            bt = stack[top];
            top--;
        }
    }
}

int main() {

    return 0;
}