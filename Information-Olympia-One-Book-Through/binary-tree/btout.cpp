#include <bits/stdc++.h>

using namespace std;

typedef struct node node;
typedef node* tree;

struct node {
    char data;
    int len;
    tree lchild, rchild;
};
tree t;

string s1, s2;

void build_tree_by_pre(tree &t, int l1, int r1, int l2, int r2) {
    if (l1 > r1) {
        return;
    }
    char c = s1[l1];
    int pos = s2.find(c);
    t = new node();
    t->data = c;
    t->len = 0;
    build_tree_by_pre(t->lchild, l1 + 1, l1 + pos - l2, l2, pos - 1);
    build_tree_by_pre(t->rchild, l1 + pos - l2 + 1, r1, pos + 1, r2);
    if (t->lchild != NULL) {
        t->len += t->lchild->len;
    }
    if (t->rchild != NULL) {
        t->len += t->rchild->len;
    }
    t->len = max(t->len, 1);
}

void preorder(tree t) {
    if (t == NULL) return;
    
    for (int i = 1; i <= t->len; i++) {
        cout << t->data;
    }
    cout << endl;
    preorder(t->lchild);
    preorder(t->rchild);
}

int main() {
    cin >> s1 >> s2;
    build_tree_by_pre(t, 0, s1.length() - 1, 0, s2.length() - 1);
    preorder(t);
    
    return 0;
}   