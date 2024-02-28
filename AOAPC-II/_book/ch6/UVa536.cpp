// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 32;
struct Node {
  Node *left, *right;
  char value;
  void init(char v) {
    left = right = NULL;
    value = v; // 变量名不能用v，不然和形参名重复，编译器会搞不清楚
  }
};
Node nodesBuf[N];
char preOrder[N], inOrder[N];
int cur;

Node* newNode() { return &(nodesBuf[cur++]); }

Node* buildTree(const char* preOrder, const char* inOrder, int len) {
  if (len == 0) return NULL;
  Node *u = newNode();
  char v = preOrder[0];
  u->init(v);
  if (len == 1) return u;
  const char *p = strchr(inOrder, preOrder[0]);
  int lLen = p - inOrder;
  int rLen = len - lLen - 1;
  u->left = buildTree(preOrder + 1, inOrder, lLen);
  u->right = buildTree(preOrder + lLen + 1, p + 1, rLen);
  return u;
}

void postPrint(Node* root) {
  if (root == NULL) return;
  postPrint(root->left);
  postPrint(root->right);
  printf("%c", root->value);
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  while (scanf("%s %s", preOrder, inOrder) == 2) {
    cur = 0;
    Node *root = buildTree(preOrder, inOrder, strlen(inOrder));
    postPrint(root);
    printf("\n");
  }
  
  
  return 0;
}