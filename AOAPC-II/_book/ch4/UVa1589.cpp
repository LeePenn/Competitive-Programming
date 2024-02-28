// Joker
#include <bits/stdc++.h>
using namespace std;
struct P {
    int x, y;
};
P operator + (const P& p1, const P& p2) {
    return (P){p1.x + p2.x, p1.y + p2.y};
}
P operator / (const P& p1, int p) {
    return (P){p1.x / p, p1.y / p};
}
bool operator == (const P& p1, const P& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}
P blackG, redG;
char board[16][16];
vector<P> 
    DIRS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}},
    HDIRS = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}},
    redPieces;
    
bool inRange(int x, int left, int right) {
    if (left > right) return inRange(x, right, left);
    return x >= left && x <= right;
}
    
bool inBPalace(const P& bp) {
    return inRange(bp.x, 1, 3) && inRange(bp.y, 4, 6);
} 

bool canFly(const P& p1, const P& p2, int sz = 0) {
    bool v = (p1.x == p2.x), h = (p1.y == p2.y);
    int lx = min(p1.x, p2.x), ux = max(p1.x, p2.x),
        ly = min(p1.y, p2.y), uy = max(p1.y, p2.y);
    int cnt = 0;
    if (v) {
        for (int i = ly + 1; i < uy; i++) {
            if (board[p1.x][i] != 0) cnt++;
        }
    } else if (h) {
        for (int i = lx + 1; i < ux; i++) {
            if (board[i][p1.y] != 0) cnt++;
        }
    }
    return cnt == sz;
}

bool checkmate(const P& r, const P& b) {
    bool ans = true;
    switch(board[r.x][r.y]) {
        case 'G': // general 将帅对面
            return r.y == b.y && canFly(r, b);
        case 'R': // chariot 车吃将
            return (r.x == b.x || r.y == b.y) && canFly(r, b);
        case 'H': // horse 马往各个方向尝试着跳
            for(const auto& HD : HDIRS) {
                P hPos = r + HD, legPos = r + HD/2;
                if(hPos == b && board[legPos.x][legPos.y] == 0) return true;
            }
            return false;
        case 'C': // 炮打
            return (r.x == b.x || r.y == b.y) && canFly(r, b, 1);
        default:
            return false;
    }
    
}

bool canWin() {
    if(blackG.y == redG.y && canFly(blackG, redG))
        return false; 

    for(const auto& D : DIRS) { // 尝试各种方向，看看能不能不被将死
        P bp = blackG + D;
        if(!inBPalace(bp)) continue; // 不能
        
        char back = board[bp.x][bp.y];
        board[bp.x][bp.y] = 0; // 红子可能被吃掉的
        
        bool live = true;
        for(const auto& r : redPieces) {
            if(board[r.x][r.y] && checkmate(r, bp)) {
                live = false;             
                break;
            }
        }
        
        board[bp.x][bp.y] = back;
        if(live) return false;
    }
    return true;
}

int main() {
    int N;    
    while(scanf("%d%d%d", &N, &(blackG.x), &(blackG.y)) == 3 && N){
        redPieces.clear();
        memset(board, 0, sizeof(board));
        for (int i = 0; i < N; i++) {
            char type[2];
            P p;
            scanf("%s%d%d", type, &(p.x), &(p.y));
            redPieces.push_back(p);
            board[p.x][p.y] = type[0];
            if(type[0] == 'G') redG = p;
        }

        puts(canWin()?"YES":"NO");        
    }
    
    return 0;
}