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

int find(VI& par, int x) {
  if(x != par[x]) return find(par, par[x]);
  return x;
}
bool same(VI& par, int x, int y) {
  return find(par, x) == find(par, y);
}
void merge(VI& par, VI& sz, int x, int y) {
  int X = find(par, x);
  int Y = find(par, y);
  if(sz[X] < sz[Y]) swap(X, Y);
  par[Y] = X;
  sz[X] += sz[Y];
  return;
}


int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("languages.in", "r", stdin);    
  freopen("languages.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);


  int n, m;
  cin >> n >> m;
  VI sz(n);
  VI par(n);

  for(int i = 0; i < n; i++) {
    sz[i] = 1;
    par[i] = i;
  }
  
  VVI l(m);
  int maxk = -1;
  int ind = -1;
  for(int i = 0; i < n; i++) {
    int k;
    cin >> k;
    if(maxk < k) {
      maxk = k;
      ind = i;
    }
    for(int j = 0; j < k; j++) {
      int lng;
      cin >> lng;
      lng--;
      l[lng].PB(i);
    }
  }

  for(int i = 0; i < m; i++) {
    for(int j = 0; j < l[i].size(); j++) {
      if(!same(par, l[i][0], l[i][j])) {
        merge(par, sz, l[i][0], l[i][j]);
      }
    }
  }

  int ret = 0;
  if(maxk == 0) {
    cout << n;
    return 0;
  }

  for(int i = 0; i < n; i++) {
    if(!same(par, ind, i)) {
      merge(par, sz, ind, i);
      ret++;
    }
  }

  cout << ret;


  return 0;
}
