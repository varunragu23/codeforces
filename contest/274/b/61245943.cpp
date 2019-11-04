#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
 
using namespace std;
 
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
 
typedef long long ll;
 
int N;
vector <int> edge[100010];
int c[100010];
ll pl[100010],minu[100010];
 
void dfs(int p, int x){
    int i;
    
    ll P = 0, M = 0;
    REP(i,edge[x].size()){
        int y = edge[x][i];
        if(y != p) dfs(x, y);
        P = max(P, pl[y]);
        M = max(M, minu[y]);
    }
    
    ll diff = c[x] - (P - M);
    if(diff > 0) P += diff; else M -= diff;
    pl[x] = P;
    minu[x] = M;
}
 
int main(void){
    int a,b,i;
    
    cin >> N;
    REP(i,N-1){
        scanf("%d%d", &a, &b);
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }
    REP(i,N) scanf("%d", &c[i]);
    
    dfs(-1, 0);
    cout << pl[0] + minu[0] << endl;
    
    return 0;
}