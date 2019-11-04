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
#include <iomanip>

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
typedef long double ll;

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
ll dist(ll a, ll b) {
  return sqrt(a*a + b*b);
}
ll findquad(ll a, ll b) {
  if (b >= 0) {
    if (a >= 0)
      return 1.00000;
    else
      return 2.00000;
  } else {
    if (a < 0)
      return 3.00000;
    else
      return 4.00000;
  }
}
ll findangle(ll a, ll b) {
  if(dist(a, b) == 0) return a;
  ll y = findquad(a, b);
  a = abs(a);
  b = abs(b);
  ll x = asin(b / dist(a, b)) * 180.00000 / PI;
  if(y == 2) {
    x = 180 - x;
  }
  else if(y == 3) {
    x = x + 180;
  }
  else if(y == 4) {
    x = 360 - x;
  }
  return x;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("viewangle.in", "r", stdin);    
  freopen("viewangle.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);


  int n;
  cin >> n;
  vector<ll> angles(n);

  for(int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    angles[i] = findangle(a, b);
  }

  sort(all(angles));

  ll ret = angles[n - 1] - angles[0];
  for(int i = 1; i < n; i++) {
    ret = min(ret, 360 - (angles[i] - angles[i - 1]));
  }
  //cout << findangle(-2, 2) << endl;
  cout << setprecision(20) << ret;

  return 0;
}