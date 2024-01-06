#include <bits/stdc++.h>

using namespace std;

int a, b;

int main() {
    FILE *fin, *fout;

    fin = fopen("input.txt", "rb");
    fout = fopen("output.txt", "wb");

    fscanf(fin, "%d%d", &a, &b);
    fprintf(fout, "%d\n", a + b);

    fclose(fin);
    fclose(fout);

    return 0;
}