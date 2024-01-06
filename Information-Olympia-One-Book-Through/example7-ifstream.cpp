#include <bits/stdc++.h>

using namespace std;

int a, b;
int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    fin >> a >> b;
    fout << a + b << endl;

    fin.close();
    fout.close();
    return 0;
}