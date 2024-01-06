#include <bits/stdc++.h>

using namespace std;

typedef struct node;
typedef node *tree;

struct node {
    char data;
    tree lchild, rchild;
}; 
tree bt;

string s1, s2;

void calc(int l1, int r1, int l2, int r2) {
    int p = s2.find(s1[l1]);
    if (p > l2) calc(l1 + 1, l1 + p - l2, l2, p - 1);
    if (p < r2) calc(l1 + p - l2 + 1, r1, p + 1, r2);
    cout << s1[l1];
}

int main() {
    cin >> s1 >> s2;
    calc(0, s1.length() - 1, 0, s2.length() - 1);
    
    return 0;
}