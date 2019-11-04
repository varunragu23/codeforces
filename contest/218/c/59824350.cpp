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
void unite(int x, int y, VI& par, VI& sz) {
  x = find(x, par);
  y = find(y, par);
  if(sz[x] < sz[y]) swap(x, y);
  par[y] = x;
  sz[x] += sz[y];
  sz[y] = 0;
}
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("iceskates.in", "r", stdin);    
  freopen("iceskates.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    VII vals(n);
    VI par(n);
    VI sz(n);
    for(int i = 0; i < n; i++) {
      cin >> vals[i].x >> vals[i].y;
      par[i] = i;
      sz[i] = 1;
    }

    int ret = 0;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(i == j) continue;
        if(!same(i, j, par)) {
          if(vals[i].x == vals[j].x or vals[i].y == vals[j].y)
          unite(i, j, par, sz);
        }
      }
    }

    for(int i = 0; i < n; i++) {
      if(sz[i]) ret++;
    }
    cout << ret - 1 << endl;

  return 0;
}
