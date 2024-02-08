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

struct Array {
    int size = -1;
    map<int, int> values;
    
    Array() {
        remove();
    }
    
    void init(int sz) {
        size = sz;
        values.clear();
    }
    
    void remove() {
        size = -1;
        values.clear();
    }
    
    bool exists() {
        return size >= 0;
    }
    
    bool setValue(int idx, int v) {
        if (idx >= size) return false;
        values[idx] = v;
        return true;
    }
    
    bool getValue(int idx, int& v) {
        if (!values.count(idx)) return false;
        v = values[idx];
        return true;
    }
};

const int N = 128;
Array arrays[N];

bool eval(const char* s, int len, int& v) {
    if (isdigit(s[0])) {
        sscanf(s, "%d", &v);
        return true;
    }
    
    char name = s[0];
    Array& ary = arrays[name];
    if (!ary.exists()) return false;
    int idx;
    if (!eval(s + 2, len - 3, idx)) return false;
    return ary.getValue(idx, v);
}

int main() {
    char line[128];
    int lineNum = 0, bugLine = 0;
    while (scanf("%s", line) == 1) {
        if (line[0] == '.') {
            if (lineNum) {
                printf("%d\n", bugLine);
                lineNum = bugLine = 0;
                for (int i = 0; i < N; i++)
                    arrays[i].remove();
            } 
            continue;
        }
        if (bugLine) continue;
        
        char* pEq = strchr(line, '=');
        if (pEq) {
            int lineLen = strlen(line), lLen = pEq - line, rv, idx;
            Array& ary = arrays[line[0]];
            if (ary.exists() 
                && eval(pEq + 1, lineLen - lLen - 1, rv) // right
                && eval(line + 2, lLen - 3, idx)
                && ary.setValue(idx, rv)) { // left
                lineNum++;
            } else {
                bugLine = lineNum + 1;
            }
        } else {
            char name = line[0];
            int size;
            sscanf(line, "%c[%d]", &name, &size);
            arrays[name].init(size);
            lineNum++;
        }
    }
    
  
    return 0;
}