#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
 
using namespace std;
 
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
 
typedef long long ll;
 
int N;
int w[100010];
 
int main(void){
    int i;
    ll l,r,Ql,Qr;
    
    cin >> N >> l >> r >> Ql >> Qr;
    REP(i,N) scanf("%d", &w[i]);
    
    ll S = 0;
    REP(i,N) S += w[i];
    
    ll ans = (1ll<<60);
    ll L = 0;
    
    REP(i,N+1){
        if(i != 0) L += w[i-1];
        ll R = S - L;
        ll tmp = L * l + R * r;
        int j = N - i;
        if(i > j) tmp += (i - j - 1) * Ql;
        if(i < j) tmp += (j - i - 1) * Qr;
        ans = min(ans, tmp);
    }
    
    cout << ans << endl;
    
    return 0;
}