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
void logger() {
  cout << "check" << endl;
}
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("annamaps.in", "r", stdin);    
  freopen("annamaps.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);


  int n;
  cin >> n;
  VVI vals(n, VI(n));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if(c == '0') vals[i][j] = 0;
      else vals[i][j] = 1;
      if(i == j) continue;
      if(vals[i][j] == 0) vals[i][j] = 1000000;
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      for(int k = 0; k < n; k++) {
        vals[i][j] = min(vals[i][j], vals[i][k] + vals[k][j]);
      }
    }
  }
  int m;

  cin >> m;

  VI p(m);

  for(int i = 0; i < m; i++) {
    cin >> p[i];
    p[i]--;
  }

  VI ret;

  


  ret.PB(p[0]);
  int last = p[0];
  for(int i = 1; i < m; i++) {
    if(vals[last][p[i]] == vals[last][p[i - 1]] + 1) {
      if(i != m - 1) continue;
      else {
        ret.PB(p[i]);
      }
    }
    else {
      if(last != p[i - 1]) ret.PB(p[i - 1]);
      //ret.PB(p[i]);
      last = p[i - 1];
      if(i == m - 1) ret.PB(p[i]);
    }
  }
  n = ret.size();
  cout << n << endl;

  for(int i = 0; i < n; i++) {
    cout << ret[i] + 1 << " ";
  }
  cout << endl;

  return 0;
}
