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
 
ll gcd(ll x, ll y){
    return x ? gcd(y%x,x) : y;
}
 
int main(void){
    ll N;
    cin >> N;
    
    ll x,y,z;
    ll ans = 0;
    
    for(x=N;x*x*x>ans;x--) for(y=x;x*y*y>ans;y--) for(z=y;x*y*z>ans;z--){
        if(gcd(x,y) == 1 && gcd(x,z) == 1 && gcd(y,z) == 1) ans = x*y*z;
    }
    
    cout << ans << endl;
    
    return 0;
}