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
// freopen("robotbreak.in", "r", stdin);    
  //freopen("robotbreak.out", "w", stdout); 

  cin.sync_with_stdio(0); cin.tie(0);

  
  

  int q;
  cin >> q;
  while(q--) {
    int x1 = -1 * 1e5;
    int x2 = 1e5;
    int y1 = x1;
    int y2 = x2;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      VI f(4);
      cin >> f[0];
      cin >> f[1];
      cin >> f[2];
      cin >> f[3];
      if(f[0] == 0) {
        x1 = max(x1, x);
      }
      if(f[1] == 0) {
        y2 = min(y2, y);
      }
      if(f[2] == 0) {
        x2 = min(x2, x);
      }
      if(f[3] == 0) {
        y1 = max(y1, y);
      }
    }
    if(x1 > x2 or y1 > y2) {cout << 0 << endl; continue;}
    cout << 1 << " " << x1 << " " << y1 << endl;
  }

  return 0;
}
