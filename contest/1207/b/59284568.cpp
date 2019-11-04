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

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("squarefilling.in", "r", stdin);    
  freopen("squarefilling.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);


  int n, m;
  cin >> n >> m;

  VVI vals(n, VI(m));
  VVI comp(n, VI(m, 0));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if(c == '0') vals[i][j] = 0;
      else vals[i][j] = 1;
    }
  }

  VII ret;

  for(int i = 0; i < n - 1; i++) {
    for(int j = 0; j < m - 1; j++) {
      if(vals[i][j] and vals[i][j + 1] and vals[i + 1][j] and vals[i + 1][j + 1]) {
        comp[i][j] = 1;
        comp[i][j + 1] = 1;
        comp[i + 1][j] = 1;
        comp[i + 1][j + 1] = 1;
        ret.PB(MP(i, j));
      }
    }
  }
  if(comp != vals) {
    cout << -1 << endl;
    return 0;
  }
  cout << ret.size() << endl;

  for(int i = 0; i < ret.size(); i++) {
    cout << ret[i].first + 1 << " " << ret[i].second + 1 << endl;
  }

  return 0;
}