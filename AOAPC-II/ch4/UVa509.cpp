// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 8;
int d, s, b, w;
char parity;
vector<int> disks[N];

void tryRecover(const vector<int>& xPos, const vector<int>& pResult, string& content) {
    vector<int> cbits(w, parity == 'O');
    bool cErr = false;
    for (int i = 0; i < w; i++) {
        if (xPos[i] == -1) {
            if (pResult[i] != cbits[i]) {
                cErr = true;
                break;
            } else {
                cbits[i] = pResult[i];
            }
        } else {
            disks[xPos[i]][i] = cbits[i] ^ pResult[i];
        }
    }
    if (cErr) return;
    stringstream ss;
    ss << uppercase << hex;
    bitset<4> bits;
    int p = 0, b = 0;
    for (int i = 0; i < w; i += s) {
        for (int j = 0; j < d; j++) {
            if (p == j) continue;
            for (int st = i; st < i + s; st++) {
                if (b == 4) {
                    ss << bits.to_ulong();
                    b = 0;
                    bits.reset();
                }
                bits.set(4 - b - 1, disks[j][st]);
                b++;
            }
        }
        p = (p + 1) % d;
    }
    ss << bits.to_ulong();
    content = ss.str();
}

int main() {
    int t = 0;
    while (cin >> d && d) {
        cin >> s >> b;
        w = s * b;
        cin >> parity;
        string line;
        vector<int> xPos(w, -1), pResult(w, 0);
        bool unRecover = false;
        for (int i = 0; i < d; i++) {
            cin >> line;
            vector<int>& disk = disks[i];
            disk.clear();
            if (unRecover) continue;
            
            for (int j = 0; j < w; j++) {
                if (line[j] == 'x') {
                    disk.push_back('x');
                    if (xPos[j] != -1) unRecover = true;
                    else xPos[j] = i;
                } else {
                    int bit = line[j] - '0';
                    pResult[j] ^= bit;
                    disk.push_back(bit);
                }
            }
        }
        
        printf("Disk set %d is ", ++t);
        string content;
        tryRecover(xPos, pResult, content);
        if (unRecover || content.empty()) printf("invalid.\n");
        else printf("valid, contents are: %s\n", content.c_str());
    }
    
    return 0;
}