#include <bits/stdc++.h>

using namespace std;

typedef struct node node;
typedef node* tree;

struct node {
    char data;
    tree lchild, rchild;
};
tree bt;
// s1: preorder/postorder, s2: inorder
string s1, s2;

void build_tree_from_pre(tree &bt, int l1, int r1, int l2, int r2) {
    if (l1 > r1) {
        bt = NULL;
        return;
    }
    bt = new node();
    bt->data = s1[l1];
    int pos = s2.find(s1[l1]);
    build_tree_from_pre(bt->lchild, l1 + 1, l1 + pos - l2, l2, pos - 1);
    build_tree_from_pre(bt->rchild, l1 + pos - l2 + 1, r1, pos + 1, r2);
}

void build_tree_from_post(tree &bt, int l1, int r1, int l2, int r2) {
    if (l1 > r1) {
        bt = NULL;
        return;
    }
    bt = new node();
    bt->data = s1[r1];
    int pos = s2.find(s1[r1]);
    build_tree_from_post(bt->lchild, l1, l1 + pos - l2 - 1, l2, pos - 1);
    build_tree_from_post(bt->rchild, l1 + pos - l2, r1 - 1, pos + 1, r2);
}

void preorder(tree &bt) {
    if (bt) {
        cout << bt->data;
        preorder(bt->lchild);
        preorder(bt->rchild);
    }
}

void postorder(tree &bt) {
    if (bt) {
        postorder(bt->lchild);
        postorder(bt->rchild);
        cout << bt->data;
    }
}

// iterater by level
void levelorder(tree &bt) {
    queue<tree> q1;
    q1.push(bt);
    while (!q1.empty()) {
        int num = q1.size();
        queue<tree> q2;
        for (int i = 1; i <= num; i++) {
            tree t = q1.front();
            q1.pop();
            cout << t->data;
            if (t->lchild) q2.push(t->lchild);
            if (t->rchild) q2.push(t->rchild);
        }
        q1 = q2;
    }
}

int main() {
    cin >> s1 >> s2;
    int l1 = s1.length(), l2 = s2.length();
    // build_tree_from_pre(bt, 0, l1 - 1, 0, l2 - 1);
    build_tree_from_post(bt, 0, l1 - 1, 0, l2 - 1);
    // preorder(bt);
    levelorder(bt);
    cout << endl;

    return 0;
}