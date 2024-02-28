// Joker
#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator << (ostream& os, vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << ' ';
    }
    return os;
}

struct Book {
    string title, author;
    Book(const string& t, const string& a) : title(t), author(a) {}
    bool operator < (const Book& o) const {
        return author < o.author || (author == o.author && title < o.title);
    }
};
vector<Book> books;
struct indexComp {
    bool operator() (const int& a, const int& b) const {
        return books[a] < books[b];
    }
};
map<string, int> bookIndice;
set<int, indexComp> shelf, lib;
string line;

void shelve() {
    for (set<int>::iterator it = shelf.begin(); it != shelf.end(); it++) {
        int idx = *it;
        set<int>::iterator slot = lib.insert(idx).first;
        if (slot == lib.begin()) {
            cout << "Put " << books[idx].title << " first" << endl;
        } else {
            slot--;
            cout << "Put " << books[idx].title << " after " << books[*slot].title << endl;
        }
    }
    shelf.clear();
    cout << "END" << endl;
}

void borrow(const string& title) {
    int idx = bookIndice[title];
    if (shelf.count(idx)) shelf.erase(idx);
    else lib.erase(idx);
}

void retBook(const string& title) {
    int idx = bookIndice[title];
    shelf.insert(idx);
}

int main() {
    while (getline(cin, line)) {
        if (line == "END") break;
        int pos = line.find(" by ");
        assert(pos != string::npos);
        string title = line.substr(0, pos), author = line.substr(pos + 4);
        int idx = books.size();
        books.push_back(Book(title, author));
        bookIndice[title] = idx;
    }
    for (int i = 0; i < books.size(); i++) 
        lib.insert(i);
    
    string cmd, title;
    while (getline(cin, line)) {
        if (line == "END") break;
        cmd = line.substr(0, 6);
        if (cmd[0] == 'S') shelve();
        else {
            title = line.substr(cmd.length() + 1);
            if (cmd[0] == 'B') borrow(title);
            else retBook(title);
        }
    }
  
    return 0;
}