#include <algorithm>
#include <assert.h>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits.h>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <utility>
#include <vector>

using namespace std;

#define EPS 1e-9
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert(B <= A && A <= C)
#define INF (int)1e9
#define MEM(a, b) memset(a, (b), sizeof(a))
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define PI 3.1415926535897932384626433832795
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()

typedef pair<int, int> PII;
typedef vector<int> VI;

const double pi = acos(-1.0);
typedef long int int32;
typedef long long int int64;
typedef map<int, int> MPII;
typedef multiset<int> MSETI;
typedef set<int> SETI;
typedef set<string> SETS;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef long long ll;

#define watch(x) cerr << (#x) << " is " << (x) << endl
#define printvii(v)                                    \
  cerr << (#v) << "=";                                 \
  for_each(v.begin(), v.end(), [](PII i) -> void {     \
    cerr << "(" << i.first << "," << i.second << "),"; \
  });                                                  \
  cerr << endl;
#define printvi(v)                                                       \
  cerr << (#v) << "=";                                                   \
  for_each(v.begin(), v.end(), [](int i) -> void { cerr << i << ","; }); \
  cerr << endl;
ll n, a, b;

ll bunchofzers(ll x, bool beg, bool end) {
  if(beg or end) {
    return (x + 1)*a + x*b;
  }
  if(x == 1) return a;
  //way one: pillars height two
  ll one = x*a + (x-1)*2*b;
  // way two: pillars height one
  ll two = 4*a + (x-2)*a + (x - 1)* b;
  return min(one, two);
}

ll bunchofones(int x) {
  ll ret = (x + 1)*2*b + x*a;
  return ret;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("gaspipeline.in", "r", stdin);    
  freopen("gaspipeline.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);


  int t;
  cin >> t;
  while(t--) {
    
    cin >> n >> a >> b;
    string s;
    cin >> s;
    VI lon(n, 1);
    //lon[n - 1]++;
    for(int i = n - 2; i >= 0; i--) {
      if(s[i] == s[i + 1]) lon[i] = lon[i + 1] + 1; 
    }
    
    
    ll ret = 0;
    ll cur = 0;
    ret = bunchofzers(lon[cur], true, false);
    cur += lon[cur];
    
    while(cur < n) {
      if(cur + lon[cur] == n) break;
      if(s[cur] == '0') ret += bunchofzers(lon[cur], false, false);
      else ret += bunchofones(lon[cur]);
      cur += lon[cur];
     
    }
    if(cur != n) {
      ret += bunchofzers(lon[cur], false, true);
    }
    else {ret -= a; ret += b;}
    cout << ret << endl;
  } 


  return 0;
}
