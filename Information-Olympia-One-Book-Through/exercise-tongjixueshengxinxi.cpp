#include <bits/stdc++.h>

using namespace std;

struct stuinfo {
    char no[22];
    char name[42];
    char sex;
    int age, score;
    char address[42];
    
    bool scan() {
        scanf("%s", no);
        if (strcmp(no, "end") == 0) {
            return false;
        }
        // 空格不能省略！
        scanf("%s %c %d %d %s\n", name, &sex, &age, &score, address);
        return true;
    }
    
    void print() {
        printf("%s %s %c %d %d %s\n", no, name, sex, age, score, address);
    }
};

struct stu {
    stuinfo d;
    stu *nxt, *prev;
} *head, *tail, *p;

int main() {
    head = new stu();
    head->nxt = NULL;
    head->prev = NULL;
    tail = head;
    while (1) {
        p = new stu();
        if (!p->d.scan()) {
            break;
        }
        p->prev = tail;
        p->nxt = NULL;
        tail->nxt = p;
        tail = p;
    }
    
    p = tail;
    while (p != head) {
        p->d.print();
        p = p->prev;
    }
    return 0;
}