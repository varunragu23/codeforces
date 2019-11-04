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
int find(int a, VI& par) {
  while(a != par[a]) a = par[a];
  return a;
}
bool same(int a, int b, vector<int>& par) {
  return find(a, par) == find(b, par);
}
void merge(int a, int b, VI& par, VI& sz) {
  a = find(a, par);
  b = find(b, par);
  if(sz[a] < sz[b]) swap(a, b);
  sz[a] += sz[b];
  par[b] = a;
  return;
}
int main(int argc, char const *argv[]) {
//  freopen("F1spanningtree.in", "r", stdin);    
  //freopen("F1spanningtree.out", "w", stdout); 

  cin.sync_with_stdio(0); cin.tie(0);

  int v, e;
  cin >> v >> e;

  vector<int> edgs(v + 1, 0);
  vector<pair<int, int>> lst(e);

  for(int i = 0; i < e; i++) {
    int a, b;
    cin >> a  >> b;
    edgs[a]++;
    edgs[b]++;
    lst[i] = {a, b};
  }

  int mx = 0;

  vector<int> par(v + 1);
  vector<int> sz(v + 1, 1);
  for(int i = 1; i <= v; i++) {
    par[i] = i;
  }

  for(int i = 1; i < v + 1; i++) {
    if(edgs[mx] < edgs[i]) mx = i;
  }

  vector<pair<int, int>> used;

  for(int i = 0; i < e; i++) {
    int a = lst[i].first;
    int b = lst[i].second;

    if(a == mx) {
      merge(a, b, par, sz);
      used.PB(lst[i]);
    }
    else if(b == mx) {
      merge(b, a, par, sz); 
      used.PB({b, a});
    }
  }

  for(int i = 0; i < e; i++) {
    int a = lst[i].first;
    int b = lst[i].second;
    if(same(a, b, par)) continue;
    merge(a, b, par, sz);
    used.PB(lst[i]);
  }

  for(int i = 0; i < v - 1; i++) {
    cout << used[i].first << " " << used[i].second << endl;
  }

  return 0;
}
