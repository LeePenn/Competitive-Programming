#include <bits/stdc++.h>

using namespace std;

struct Student {
    string name;
    int month, day;
}stu[100005];

bool cmp(const Student &stu1, const Student &stu2) {
    if (stu1.month != stu2.month) return stu1.month < stu2.month;
    if (stu1.day != stu2.day) return stu1.day < stu2.day;
    if (stu1.name.length() != stu2.name.length()) return stu1.name.length() < stu2.name.length();
    return stu1.name < stu2.name;
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].month >> stu[i].day;
    }
    sort(stu, stu + n, cmp);
    bool flag = false;
    for (int i = 0; i < n - 1; i++) {
        if (stu[i].month == stu[i + 1].month && stu[i].day == stu[i + 1].day) {
            cout << stu[i].month << ' ' << stu[i].day << ' ' << stu[i].name;
            while (stu[i].month == stu[i + 1].month && stu[i].day == stu[i + 1].day) {
                flag = true;
                cout << ' ' << stu[++i].name;
            }
            cout << endl;
        }
    }
    if (!flag) cout << "None";

    return 0;
}

