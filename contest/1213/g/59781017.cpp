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
#define x first
#define y second

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

int find(int x, VI& par) {
  while(x != par[x]) x = par[x];
  return x;
}

bool same(int x, int y, VI& par) {
  return find(x, par) == find(y, par);
}

void unite(int x, int y, VI& par, vector<ll>& sz, ll& ans) {
  x = find(x, par);
  y = find(y, par);
  if(sz[x] < sz[y]) swap(x, y);
  ans -= (sz[x]*(sz[x] - 1))/2;
  ans -= (sz[y]*(sz[y] - 1))/2;
  sz[x] += sz[y];
  sz[y] = 0;
  ans += (sz[x]*(sz[x] - 1))/2;
  par[y] = x;
}

static bool comp1(VI& a, VI& b) {
  return a[2] < b[2];
}

static bool comp2(pair<ll, ll>& a, pair<ll, ll>& b) {
  return a.x < b.x;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("pathqueries.in", "r", stdin);    
  freopen("pathqueries.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  ll n;
  ll m;
  cin >> n >> m;
  VI par(n);
  vector<ll> sz(n);
  for(int i = 0 ; i < n; i++) {
    par[i] = i;
    sz[i] = 1;
  }
  VVI edg(n - 1, VI(3));
  
  for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < 3; j++) {
      cin >> edg[i][j];
      if(j <= 1) edg[i][j]--;
    }
  }

  vector<ll> qs(m);

  for(int i = 0; i < m; i++) {
    cin >> qs[i];
  }

  ll ans = 0;

  sort(edg.begin(), edg.end(), comp1);

  vector<pair<ll, ll>> q(m);

  for(int i = 0; i < m; i++) {
    q[i].x = qs[i];
    q[i].y = i;
  }

  sort(q.begin(), q.end(), comp2);

  int pos = 0;

  for(int i = 0; i < n - 1; i++) {
    while(edg[i][2] > q[pos].x) {
      q[pos].x = ans;
      pos++;
      if(pos == m) break;
    }
    if(pos == m) break;
    unite(edg[i][0], edg[i][1], par, sz, ans);
  }

  while(pos < m) {
    q[pos].x = ans;
    pos++;
  }

  for(int i = 0; i < m; i++) {
    qs[q[i].y] = q[i].x;
  }

  for(int i = 0; i < m; i++) {
    cout << qs[i] << " ";
  }
  cout << endl;

  return 0;
}
