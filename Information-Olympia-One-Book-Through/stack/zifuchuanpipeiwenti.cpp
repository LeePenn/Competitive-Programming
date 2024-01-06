#include <bits/stdc++.h>

using namespace std;

int n;
char a[255];
stack<char> s;
int square_bracket, parentheses, angle_bracket;

int main() {
    cin >> n;
    while (n--) {
        scanf("%s", a);
        int l = strlen(a);
        angle_bracket = parentheses = square_bracket = 0;
        while (!s.empty()) s.pop();
        int i = 0;
        bool ok = true;
        while (i < l) {
            if (a[i] == '<') {
                s.push(a[i]);
                angle_bracket++;
                i++;
            } else if (a[i] == '(') {
                if (angle_bracket > 0) {
                    ok = false;
                    break;
                }
                s.push(a[i]);
                parentheses++;
                i++;
            } else if (a[i] == '[') {
                if (angle_bracket > 0 || parentheses > 0) {
                    ok = false;
                    break;
                }
                s.push(a[i]);
                square_bracket++;
                i++;
            } else if (a[i] == '{') {
                if (angle_bracket > 0 || parentheses > 0 || square_bracket > 0) {
                    ok = false;
                    break;
                }
                s.push(a[i]);
                i++;
            } else if (a[i] == '>') {
                if (s.empty() || s.top() != '<') {
                    ok = false;
                    break;
                }
                s.pop();
                angle_bracket--;
                i++;
            } else if (a[i] == ')') {
                if (s.empty() || s.top() != '(') {
                    ok = false;
                    break;
                }
                s.pop();
                parentheses--;
                i++;
            } else if (a[i] == ']') {
                if (s.empty() || s.top() != '[') {
                    ok = false;
                    break;
                }
                s.pop();
                square_bracket--;
                i++;
            } else if (a[i] == '}') {
                if (s.empty() || s.top() != '{') {
                    ok = false;
                    break;
                }
                s.pop();
                i++;
            }
        }
        if (!ok || !s.empty()) printf("NO\n");
        else printf("YES\n");
    }
    

    return 0;
}