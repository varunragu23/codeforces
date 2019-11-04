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
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
 
double p[210];
int a[210];
double dp[210][210][210]; // pos, won, cap
 
int main(void){
    int N,L,K,i,j,k;
    
    cin >> N >> L >> K;
    REP(i,N) cin >> p[i];
    REP(i,N) cin >> a[i];
    REP(i,N) p[i] /= 100.0;
    
    dp[0][0][0] = 1.0;
    
    REP(i,N) REP(j,i+1) REP(k,N+1){
        int c = a[i] + 1;
        // win
        dp[i+1][j+1][min(k+c,N)] += dp[i][j][k] * p[i];
        // lose
        dp[i+1][j][k] += dp[i][j][k] * (1.0 - p[i]);
    }
    
    double ans = 0.0;
    REP(i,N+1) REP(j,N+1) if(i >= L && K+j-i >= 0) ans += dp[N][i][j];
    printf("%.9f\n",ans);
    
    return 0;
}