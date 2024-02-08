// Joker
#include <bits/stdc++.h>
using namespace std;

const int N = 10000 + 3;
map<string, int> software_id;
string software[N];
vector<int> depend[N], depended[N];
int status[N];
int tot;
vector<int> installed;

int getID(const string& s) {
  if (!software_id.count(s)) {
    software_id[s] = ++tot;
    software[tot] = s;
  }
  return software_id[s];
}

bool needed(int id) {
  for (int i = 0; i < depended[id].size(); i++) {
    if (status[depended[id][i]]) return true;
  }
  return false;
}

void recur_install(int id, bool flag = true) {
  if (status[id]) return;
  for (int i = 0; i < depend[id].size(); i++) {
    recur_install(depend[id][i], false);
  }
  printf("   Installing %s\n", software[id].c_str());
  status[id] = flag ? 1 : 2;
  installed.push_back(id);
}

void recur_remove(int id, bool flag = true) {
  if ((flag || status[id] == 2) && !needed(id)) {
    status[id] = 0;
    installed.erase(remove(installed.begin(), installed.end(), id), installed.end());
    printf("   Removing %s\n", software[id].c_str());
    for (int i = 0; i < depend[id].size(); i++) {
      recur_remove(depend[id][i], false);
    }
  }
}

void List() {
  for (int i = 0; i < installed.size(); i++) {
    printf("   %s\n", software[installed[i]].c_str());
  }
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  string line, cmd;
  tot = 0;
  for (;;) {
    getline(cin, line);
    printf("%s\n", line.c_str());
    if (line == "END") break;
    stringstream ss(line);
    ss >> cmd;
    string s1, s2;
    switch (cmd[0]) {
      case 'D':
      {
        ss >> s1;
        int id1 = getID(s1);
        while (ss >> s2 && s2.size()) {
          int id2 = getID(s2);
          depend[id1].push_back(id2);
          depended[id2].push_back(id1);
        }
        break;
      }
      case 'I':
      {
        ss >> s1;
        int id1 = getID(s1);
        if (status[id1]) {
          printf("   %s is already installed.\n", software[id1].c_str());
        } else {
          recur_install(id1, true);
        }
        break;
      }
      case 'R':
      {
        ss >> s1;
        int id1 = getID(s1);
        if (!status[id1]) {
          printf("   %s is not installed.\n", software[id1].c_str());
        } else if (needed(id1)) printf("   %s is still needed.\n", software[id1].c_str());
        else recur_remove(id1, true);
        break;
      }
      case 'L':
      {
        List();
        break;
      }
      default:
        break;
    }
  }
  
  
  return 0;
}