// Joker
#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
vector<string> expression;
stack<string> ops;
stack<string> nums;
stack<int> nums2;

int str2num(string s) {
  int num = 0;
  for (int i = 0; i < s.size(); i++) {
    num = num * 10 + (s[i] - '0');
  }
  return num;
}

bool calc(const vector<string>& exp, string& equation) {
  //cout << "Calc" << endl;
  while (ops.size()) ops.pop();
  while (nums.size()) nums.pop();
  while (nums2.size()) nums.pop();
  equation.clear();
  for (const auto& v : exp) {
    equation += v;
    if (isdigit(v[0])) nums.push(v);
    else {
      if (v == "*") {
        while (!ops.empty() && ops.top() == "*") {
          string t = ops.top(); ops.pop();
          nums.push(t);
        }
        ops.push(v); 
      } else {
        while (!ops.empty()) {
          string t = ops.top(); ops.pop();
          nums.push(t);
        }
        ops.push(v); 
      }
    }
  }
  while (!ops.empty()) {
    string t = ops.top(); ops.pop();
    nums.push(t);
  }
  while (!nums.empty()) {
    string t = nums.top(); nums.pop();
    ops.push(t);
  }
  
  while (ops.size()) {
    string op = ops.top(); ops.pop();
    if (isdigit(op[0])) nums2.push(str2num(op));
    else {
      int num1 = nums2.top(); nums2.pop();
      int num2 = nums2.top(); nums2.pop();
      if (op == "+") {
        nums2.push(num1 + num2);
      } else if (op == "-") {
        nums2.push(num2 - num1);
      } else {
        nums2.push(num1 * num2);
      }
    }
  }
  int t = nums2.top(); nums2.pop();
  return t == 2000;
}

void dfs(int cur, const string& line, vector<string>& exp) {
  if (cur == line.size()) {
    string equation;
    //for (const auto& v : exp) cout << v << ' ';
    //cout << endl;
    if (calc(exp, equation)) {
      ans.push_back(equation);
    }
    return;
  }
  
  
  string num;
  for (int i = cur; i < line.size(); i++) {
    num += line[i];
    if (i == line.size() - 1) {
      exp.push_back(num);
      dfs(i + 1, line, exp);
      exp.pop_back();
    } else {
      if (num[0] == '0') {
        exp.push_back(num); 
        exp.push_back("+"); dfs(i + 1, line, exp); exp.pop_back();
        exp.push_back("-"); dfs(i + 1, line, exp); exp.pop_back();
        exp.push_back("*"); dfs(i + 1, line, exp); exp.pop_back();
        exp.pop_back();
        return;
      } else if (num[0] != '0') {
        exp.push_back(num); 
        exp.push_back("+"); dfs(i + 1, line, exp); exp.pop_back();
        exp.push_back("-"); dfs(i + 1, line, exp); exp.pop_back();
        exp.push_back("*"); dfs(i + 1, line, exp); exp.pop_back();
        exp.pop_back();
      }
      
    }
  }
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  
  string line;
  for (int kase = 1; cin >> line && line != "="; kase++) {
    printf("Problem %d\n", kase);
    line = line.substr(0, line.size() - 1);
    // 2000= should be IMPOSSIBLE!!!!
    if (line == "2000") { puts("  IMPOSSIBLE"); continue; }
    ans.clear(); expression.clear();
    dfs(0, line, expression);
    
    if ((int)ans.size()) {
      sort(ans.begin(), ans.end());
      for (int i = 0; i < (int)ans.size(); i++) {
        printf("  %s=\n", ans[i].c_str());
      }
    } else printf("  IMPOSSIBLE\n");
  }
  
  
  return 0;
}