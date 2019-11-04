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
 
typedef long long ll;
 
int N,D;
int x[100010];
 
int main(void){
    int i,j;
    
    cin >> N >> D;
    REP(i,N) scanf("%d", &x[i]);
    
    ll ans = 0;
    j = 0;
    REP(i,N){
        while(j+1 < N && x[j+1] - x[i] <= D) j++;
        ll tmp = j - i;
        ans += tmp * (tmp - 1) / 2;
    }
    
    cout << ans << endl;
    
    return 0;
}