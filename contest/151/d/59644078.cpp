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

ll n, m, k;

ll binpow(ll n, ll m) {
  if(m == 0) return 1;
  if(m == 1) return n;
  ll ret = binpow(n, m/2)%MOD;
  ret = ret*ret%MOD;
  if(m%2) ret *= n;
  ret = ret % MOD;
  return ret;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("quantstring.in", "r", stdin);    
  freopen("quantstring.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);


  cin >> n >> m >> k;

  if(k > n or k == 1) {
    cout << binpow(m, n) << endl;
  }
  else if(k == n) {
    ll ret = binpow(m, n/2);
    if(n%2) ret *= m;
    ret = ret % MOD;
    cout << ret << endl;
  }
  else if(k % 2) {
    cout << binpow(m, 2) << endl;
  }
  else {
    cout << m << endl;
  }

  return 0;
}
