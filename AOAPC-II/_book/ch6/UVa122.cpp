// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 260;
struct Node {
  int v;
  bool have_value;
  Node *left, *right;
  Node() : have_value(false), left(NULL), right(NULL) {}
};
Node* root;

queue<Node*> freenodes;

void init() {
  for (int i = 0; i < N; i++) freenodes.push(new Node());
}

Node* newnode() { 
  Node* u = freenodes.front(); freenodes.pop();
  u->left = u->right = NULL; u->have_value = false;
  return u; 
}

void deletenode(Node* u) {
  freenodes.push(u);
}

void remove_tree(Node *u) {
  if (u == NULL) return;
  if (u->left != NULL) remove_tree(u->left);
  if (u->right != NULL) remove_tree(u->right);
  deletenode(u);
}


bool failed;

void addnode(int v, char *s) {
  int n = strlen(s);
  Node *u = root;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      if (u->left == NULL) u->left = newnode();
      u = u->left;
    } else if (s[i] == 'R') {
      if (u->right == NULL) u->right = newnode();
      u = u->right;
    }
  }
  if (u->have_value) failed = true;
  u->v = v; u->have_value = true;
}

char s[N];
bool read_input() {
  failed = false;
  remove_tree(root);
  root = newnode();
  for (;;) {
    if (scanf("%s", s) != 1) return false;
    if (!strcmp(s, "()")) break;
    int v;
    sscanf(s + 1, "%d", &v);
    addnode(v, strchr(s, ',') + 1);
  }
  return true;
}

bool bfs(vector<int>& ans) {
  queue<Node*> q;
  ans.clear();
  q.push(root);
  while (!q.empty()) {
    Node* u = q.front(); q.pop();
    if (!u->have_value) failed = true;
    ans.push_back(u->v);
    if (u->left != NULL) q.push(u->left);
    if (u->right != NULL) q.push(u->right);
  }
  return true;
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  init();
  vector<int> ans;
  while (read_input()) {
    if (!bfs(ans)) failed = false;
    if (failed) printf("not complete");
    else {
      for (int i = 0; i < ans.size(); i++) {
        if (i) printf(" ");
        printf("%d", ans[i]);
      }
    }
    printf("\n");
  }
  
  
  
  return 0;
}