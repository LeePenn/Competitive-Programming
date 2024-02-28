// Joker
#include <bits/stdc++.h>
using namespace std;

const int H = 200 + 4;
const int W = 50 * 4 + 4;
char bin[256][5];
int grid[H][W], color[H][W];
int h, w;
const int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
vector<int> word;
vector<set<int> > word_hollow;
const char* code = "WAKJSD";

void decode(char c, int row, int col) {
  for (int i = 0; i < 4; i++) 
    grid[row][col + i] = bin[c][i] - '0';
}

bool inRange(int row, int col) {
  return row >= 0 && row < h && col >= 0 && col < w;
}

void dfs(int row, int col, int c) {
  color[row][col] = c;
  for (int i = 0; i < 4; i++) {
    int row2 = row + dr[i], col2 = col + dc[i];
    if (inRange(row2, col2) && grid[row][col] == grid[row2][col2] && !color[row2][col2]) 
      dfs(row2, col2, c);
  }
}

void find_neighbors(int row, int col) {
  for (int i = 0; i < 4; i++) {
    int row2 = row + dr[i], col2 = col + dc[i];
    if (inRange(row2, col2) && !grid[row2][col2] && color[row2][col2] != 1) {
      word_hollow[color[row][col]].insert(color[row2][col2]);
    }
  }
}

char recognize(int c) {
  return code[word_hollow[c].size()];
}

int main() {
  //std::ios::sync_with_stdio(false);
  //std::cin.tie(0);
  
  strcpy(bin['0'], "0000");
  strcpy(bin['1'], "0001");
  strcpy(bin['2'], "0010");
  strcpy(bin['3'], "0011");
  strcpy(bin['4'], "0100");
  strcpy(bin['5'], "0101");
  strcpy(bin['6'], "0110");
  strcpy(bin['7'], "0111");
  strcpy(bin['8'], "1000");
  strcpy(bin['9'], "1001");
  strcpy(bin['a'], "1010");
  strcpy(bin['b'], "1011");
  strcpy(bin['c'], "1100");
  strcpy(bin['d'], "1101");
  strcpy(bin['e'], "1110");
  strcpy(bin['f'], "1111");
  
  int kase = 0;
  while (scanf("%d %d", &h, &w) == 2 && h) {
    memset(grid, 0, sizeof(grid));
    char line[50 + 4];
    for (int i = 0; i < h; i++) {
      scanf("%s", line);
      for (int j = 0; j < w; j++) {
        decode(line[j], i + 1, j * 4 + 1);
      }
    }
    
    h += 2;
    w = (w << 2) + 2;
    memset(color, 0, sizeof(color));
    word.clear();
    int cnt = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (!color[i][j]) {
          dfs(i, j, ++cnt);
          if (grid[i][j]) word.push_back(cnt);
        }
      }
    }
    word_hollow.clear();
    word_hollow.resize(cnt + 1);
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (grid[i][j]) 
          find_neighbors(i, j);
      }
    }
    vector<char> ans;
    for (int i = 0; i < word.size(); i++) {
      ans.push_back(recognize(word[i]));
    }
      
    sort(ans.begin(), ans.end());
    
    printf("Case %d: ", ++kase);
    for (int i = 0; i < ans.size(); i++) 
      printf("%c", ans[i]);
    printf("\n");
  }
  
  return 0;
}