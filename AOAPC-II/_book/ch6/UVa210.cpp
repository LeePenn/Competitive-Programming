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

const int N = 1000;

int nProc, c[5], quantum, var[26], proc[N];
char cmd[N][10];

deque<int> readyQ;
queue<int> blockQ;

bool locked;

void run(int pid) {
  
  int tot = quantum;
  while (tot > 0) {
    char* p = cmd[proc[pid]];
    switch (p[2]) {
      case '=':
        var[p[0] - 'a'] = isdigit(p[5]) ? (p[4] - '0') * 10 + p[5] - '0' : p[4] - '0';
        tot -= c[0];
        break;
      case 'i':
        printf("%d: %d\n", pid + 1, var[p[6] - 'a']);
        tot -= c[1];
        break;
      case 'c':
        if (locked) { blockQ.push(pid); return; }
        locked = true;
        tot -= c[2];
        break;
      case 'l':
        locked = false;
        if (!blockQ.empty()) {
          int bf = blockQ.front(); blockQ.pop();
          readyQ.push_front(bf);
        }
        tot -= c[3];
        break;
      case 'd':
        return;
      default:
        break;
    }
    proc[pid]++;
  }
  readyQ.push_back(pid);
  
}

int main() {
  // 这里不注释掉就是错，具体需要了解c++stdio机制
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  int T;
  cin >> T;
  while (T--) {
    scanf("%d %d %d %d %d %d %d\n", &nProc, &c[0], &c[1], &c[2], &c[3], &c[4], &quantum);
    //cin >> nProc >> c[0] >> c[1] >> c[2] >> c[3] >> c[4] >> quantum;
    memset(var, 0, sizeof(var));;
    locked = false;
    int line = 0;
    for (int i = 0; i < nProc; i++) {
      fgets(cmd[line++], 10, stdin);
      proc[i] = line - 1;
      while (cmd[line - 1][2] != 'd') {
        fgets(cmd[line++], 10, stdin);
      }
      readyQ.push_back(i);
    }
    while (!readyQ.empty()) {
      int pid = readyQ.front(); readyQ.pop_front();
      run(pid);
    }
    if (T) printf("\n");
  }
  
  return 0;
}