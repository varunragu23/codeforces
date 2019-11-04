#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
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

int a, b, c, d, n;
bool inside(int i, int j, VVI& g) {
  if (i < 0 or j < 0 or i >= g.size() or j >= g[0].size()) return false;
  if (g[i][j] == -1) return true;
  return false;
}

int main(int argc, char const* argv[]) {
#ifndef ONLINE_JUDGE
  freopen("divislands.in", "r", stdin);
  freopen("divislands.out", "w", stdout);
#endif
  cin.sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b >> c >> d >> n;

  VI vals(n);

  for (int i = 0; i < n; i++) {
    cin >> vals[i];
  }

  vector<vector<char>> g(max(b, d), vector<char>(a + c, '.'));
  VVI ga(b, VI(a, -1));
  VVI gb(d, VI(c, -1));
  /*VI dx(6, 0);
  VI dy(6, 0);
  dx[0] = 1;
  dy[1] = 1;
  

  if(b < d) dx[2] = -1;
  else dx[2] = 1;

  dy[3] = 1;
  dx[4] = -1;
  dy[5] = -1;

*/

  PII ab;
  PII cd;

  if (b % 2) {
    ab.first = b - 1;
    ab.second = 0;
  } else {
    ab.first = b - 1;
    ab.second = a - 1;
  }

  cd = MP(0, 0);

  int x = 0;
  map<int, PII> w;

  while (true) {
    ga[ab.x][ab.y] = x;
    w[x] = ab;
    
    x++;
    if (inside(ab.x, ab.y + 1, ga))
      ab.y++;
    else if (inside(ab.x, ab.y - 1, ga))
      ab.y--;
    else if (inside(ab.x - 1, ab.y, ga))
      ab.x--;
    else
      break;
    //cout << ab.x << " " << ab.y << endl;
  }

 
  map<int, PII> we;
  while (true) {
    gb[cd.x][cd.y] = x;
    we[x] = MP(cd.first, cd.second + a);
    x++;
    if (inside(cd.x, cd.y + 1, gb))
      cd.y++;
    else if (inside(cd.x, cd.y - 1, gb))
      cd.y--;
    else if (inside(cd.x + 1, cd.y, gb))
      cd.x++;
    else
      break;
    // cout << cd.x << " " << cd.y << endl;
  }

  for (int i = 1; i < n; i++) {
    vals[i] += vals[i - 1];
  }

  for (int i = 0; i < n; i++) {
    int start, end;
    if (i == 0)
      start = 0;
    else
      start = vals[i - 1];
    end = vals[i];
    for (int j = start; j < end; j++) {
      PII put;
      if(j < a*b) put = w[j];
      else put = we[j];
      
      g[put.x][put.y] = 'a' + i;
    }
  }
  cout << "YES" << endl;
  for (auto& x : g) {
    for (auto& y : x) {
      cout << y;
    }
    cout << endl;
  }
 

  return 0;
}
