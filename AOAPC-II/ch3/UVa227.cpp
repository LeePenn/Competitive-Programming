// Joker
#include <bits/stdc++.h>
using namespace std;
const int N = 256;
string line;
vector<string> grid;
int sx, sy;
string op;

bool check(char ch) {
    int dx = -1, dy = -1;
    switch (ch) {
        case 'A':
        {
            dx = -1, dy = 0;
            break;
        }
        case 'B':
        {
            dx = 1, dy = 0;
            break;
        }
        case 'L':
        {
            dx = 0, dy = -1;
            break;
        }
        default:
        {
            dx = 0, dy = 1;
            break;
        }
    }
    int nx = sx + dx, ny = sy + dy;
    //cout << nx << ' ' << ny << endl;
    return nx >= 0 && nx < 5 && ny >= 0 && ny < 5;
}

void move(char ch) {
    int dx = -1, dy = -1;
    switch (ch) {
        case 'A':
        {
            dx = -1, dy = 0;
            break;
        }
        case 'B':
        {
            dx = 1, dy = 0;
            break;
        }
        case 'L':
        {
            dx = 0, dy = -1;
            break;
        }
        default:
        {
            dx = 0, dy = 1;
            break;
        }
    }
    int nx = sx + dx, ny = sy + dy;
    char t = grid[sx][sy];
    grid[sx][sy] = grid[nx][ny];
    grid[nx][ny] = t;
    sx = nx, sy = ny;
}

int main() {
    int id = 0;
    while (1) {
        grid.clear();
        for (int i = 0; i < 5; i++) {
            getline(cin, line);
            //cout << line << endl;
            if (line == "Z") return 0;
            //assert(line.size() == 5);
            for (int j = 0; j < 5; j++) {
                if (line[j] == ' ') {
                    sx = i, sy = j;
                }
            }
            grid.push_back(line);
        }
        //cout << sx << ' ' << sy << endl;
        string op = "";
        while (1) {
            getline(cin, line);
            bool end = *(line.rbegin()) == '0';
            if (!end) op.append(line);
            else op.append(line, 0, line.size() - 1);
            if (end) break;
        }
        if (id > 0) cout << endl;
        printf("Puzzle #%d:\n", ++id);
        bool flag = false;
        for (int i = 0; i < op.size(); i++) {
            //cout << op[i] << endl;
            if (!check(op[i])) {
                cout << "This puzzle has no final configuration." << endl;
                flag = true;
                break;
            }
            move(op[i]);
            //for (int i = 0; i < 5; i++) {
                //for (int j = 0; j < 4; j++) {
                    //printf("%c ", grid[i][j]);
                //}
                //printf("%c\n", grid[i][4]);
            //}
            //puts("");
        }
        if (flag) continue;
        
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (j) cout << ' ';
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}