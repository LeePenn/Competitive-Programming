```cpp
#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;

struct BigInteger {
  static const int BASE = 100000000;
  static const int WIDTH = 8;
  vector<int> s;

  BigInteger(long long num = 0) { *this = num; } // 构造函数
  BigInteger operator = (long long num) { // 赋值运算符
    s.clear();
    do {
      s.push_back(num % BASE);
      num /= BASE;
    } while(num > 0);
    return *this;
  }
  BigInteger operator = (const string& str) { // 赋值运算符
    s.clear();
    int x, len = (str.length() - 1) / WIDTH + 1;
    for(int i = 0; i < len; i++) {
      int end = str.length() - i*WIDTH;
      int start = max(0, end - WIDTH);
      sscanf(str.substr(start, end-start).c_str(), "%d", &x);
      s.push_back(x);
    }
    return *this;
  }
  BigInteger operator + (const BigInteger& b) const {
    BigInteger c;
    c.s.clear();
    for(int i = 0, g = 0; ; i++) {
      if(g == 0 && i >= s.size() && i >= b.s.size()) break;
      //int x = g;
      if(i < s.size()) g += s[i];
      if(i < b.s.size()) g += b.s[i];
      c.s.push_back(g % BASE);
      g /= BASE;
    }
    return c;
  }
};

ostream& operator << (ostream &out, const BigInteger& x) {
  out << x.s.back();
  for(int i = x.s.size()-2; i >= 0; i--) {
    char buf[20];
    sprintf(buf, "%08d", x.s[i]);
    for(int j = 0; j < strlen(buf); j++) out << buf[j];
  }
  return out;
}

istream& operator >> (istream &in, BigInteger& x) {
  string s;
  if(!(in >> s)) return in;
  x = s;
  return in;
}

#include<set>
#include<map>
set<BigInteger> s;
map<BigInteger, int> m;

int main() {
  BigInteger y;
  BigInteger x = y;
  BigInteger z = 123;

  BigInteger a, b;
  cin >> a >> b;
  cout << a + b << "\n";
  cout << BigInteger::BASE << "\n";
  return 0;
}
```


```cpp
// Joker
#include <bits/stdc++.h>
using namespace std;
struct BigInteger {
    static const int BASE = 100000000;
    static const int W = 8;
    vector<int> s;
    
    BigInteger(long long num = 0) {
        *this = num;
    }
    
    BigInteger operator = (long long num) {
        s.clear();
        while (num > 0) {
            s.push_back(num % BASE);
            num /= BASE;
        }
        return *this;
    }
    
    BigInteger operator = (const string& str) {
        s.clear();
        int x;
        int tot = (str.length() - 1) / W + 1;
        for (int i = 0; i < tot; i++) {
            int end = str.length() - i * W;
            int start = max(0, end - W);
            sscanf(str.substr(start, end - start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }
    
    BigInteger operator + (const BigInteger& a) {
        BigInteger b;
        b.s.clear();
        for (int i = 0, g = 0; ; i++) {
            if (!g && i >= s.size() && i >= a.s.size()) break;
            if (i < s.size()) g += s[i];
            if (i < a.s.size()) g += a.s[i];
            b.s.push_back(g % BASE);
            g /= BASE;
        }
        return b;
    }
};

ostream& operator << (ostream& os, const BigInteger& a) {
    os << a.s.back();
    for (int i = a.s.size() - 2; ~i; i--) {
        //char buf[15];
        //sprintf(buf, "%08d", a.s[i]);
        //for (int j = 0; j < strlen(buf); j++) os << buf[j];
        os << a.s[i];
    }
    return os;
}

istream& operator >> (istream& ins, BigInteger& a) {
    string s;
    if (!(ins >> s)) return ins;
    a = s;
    return ins;
}

int main() {
    BigInteger y;
    BigInteger x = y;
    BigInteger z = 123;

    BigInteger a, b;
    cin >> a >> b;
    cout << a + b << "\n";
    cout << BigInteger::BASE << "\n";
  
    return 0;
}
```