#include <bits/stdc++.h>

using namespace std;

float calc() {
    char str[50];
    scanf("%s", str);
    if (strlen(str) > 1) {
        float num;
        sscanf(str, "%f", &num);
        return num;
        
    }
    float a = calc();
    float b = calc();
    switch(str[0]) {
        case '+': 
            return a + b;
        case '-': 
            return a - b;
        case '*': 
            return a * b;
        default: 
            return a / b;
    }
}

int main() {
    float ans = calc();
    printf("%f\n", ans);

    return 0;
}