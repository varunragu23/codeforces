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

int p(PII a, PII b, PII c) {
  int ret = 4;
  if(a.x == b.x) ret--;
  if(a.y == b.y) ret--;
  if(b.x == c.x) ret--;
  if(b.y == c.y) ret--;
  if(a.x == b.x and b.x == c.x) ret--;
  if(a.y == b.y and b.y == c.y) ret--;
  if(ret >= 3) ret--;
  return ret;
}

bool share(PII a, PII b) {
  return a.x == b.x or a.y == b.y;
}

bool isTwo(PII a, PII b, PII c) {
  if (share(a, b) and
      (((c.x <= a.x and c.x <= b.x) or (c.x >= a.x and c.x >= b.x)) and
       ((c.y <= a.y and c.y <= b.y) or (c.y >= a.y and c.y >= b.y)))) return true;
  return false;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("polyline.in", "r", stdin);    
  freopen("polyline.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);


  PII a;
  PII b;
  PII c;
  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

  /*VI s(6);

  s[0] = p(a, b, c);
  s[1] = p(a, c, b);
  s[2] = p(b, a, c);
  s[3] = p(b, c, a);
  s[4] = p(c, b, a);
  s[5] = p(c, a, b);
  
  cout << *min_element(s.begin(), s.end()) << endl;
*/


  if((a.x == b.x and b.x == c.x) or (a.y == b.y and b.y == c.y)) {cout << 1 << endl; return 0;}
  //determine if answer is two;
  if(isTwo(a, b, c) or isTwo(a, c, b) or isTwo(b, c, a)) {
    cout << 2 << endl;
    return 0;
  }

  cout << 3 << endl;
  return 0;

  return 0;
}
