#include <bits/stdc++.h>

using namespace std;

int a, b;

int main() {
    FILE *fin, *fout;

    fin = stdin;
    fout = stdout;

    fscanf(fin, "%d%d", &a, &b);
    fprintf(fout, "%d\n", a + b);


    return 0;
}