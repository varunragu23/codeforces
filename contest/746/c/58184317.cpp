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
int dist(int end, int pos, int des, int& dir, int sp) {
  if(des <= pos and dir == -1) {
    return (pos - des) * sp;
  }
  else if(des > pos and dir == -1) {
    int ret = dist(end, pos, 0, dir, sp);
    dir *= -1;
    ret += dist(end, 0, des, dir, sp);
    return ret;
  }
  else if(des >= pos and dir == 1) {
    return (des - pos) * sp;
  }
  else {
    int ret = dist(end, pos, end, dir, sp);
    dir *= -1;
    ret += dist(end, end, des, dir, sp);
    return ret;
  }
}
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("tram.in", "r", stdin);    
  freopen("tram.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);


  int s, x1, x2, t1, t2, p, d;

  cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;

 
  int igor = abs(x2 - x1)*t2;

  int tram = dist(s, p, x1, d, t1) + dist(s, x1, x2, d, t1);

  cout << min(igor, tram);



  return 0;
}
