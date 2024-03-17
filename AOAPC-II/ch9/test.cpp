// Folding, ACM/ICPC NEERC 2001, UVa1630
// 陈锋
#include <iostream>
#include <string>
#include <climits>
#include <cassert>
#include <sstream>
#include <vector>

#define _for(i,a,b) for( int i=(a); i<(b); ++i)
#define _rep(i,a,b) for( int i=(a); i<=(b); ++i)

using namespace std;
const int INF = 0x3f3f3f3f, MAXN = 104;
string S, Fold[MAXN][MAXN];

int main(){
    vector<pair<int, int>> D;
    D.push_back(make_pair(0, 1));
    D.push_back(make_pair(1, 1));
    
    sort(D.begin(), D.end());
    D.resize(unique(D.begin(), D.end()) - D.begin());
    
    printf("%d\n", D.size());
    
    
}
// 1992297  2692    Folding Accepted    C++11   0.062   2016-07-20 09:47:42