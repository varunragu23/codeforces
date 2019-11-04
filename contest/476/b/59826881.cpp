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
#include <iomanip>

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
typedef long double ll;

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
int c(int n, int  r) {
  int top = 1;
  int b1 = 1;
  int b2 = 1;
  for(int i = 1; i <= n; i++) {
    top *= i;
  }
  for(int i = 1; i <= r; i++) {
    b1 *= i;
  }
  for(int i = 1; i <= n - r; i++) {
    b2 *= i;
  }
  return top/b1/b2;
}
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("wifidreammoon.in", "r", stdin);    
  freopen("wifidreammoon.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  string a;
  string b;
  cin >> a >> b;

  int drazil = 0;
  int dream = 0;
  int q = 0;
  for(int i = 0; i < a.size(); i++) {
    if(a[i] == '+') drazil++;
    else drazil--;
    if(b[i] == '+') dream++;
    else if(b[i] == '-') dream--;
    else q++;
  }

  int dif = abs(drazil - dream);

  int total = 1;

  for(int i = 0; i < q; i++) {
    total *= 2;
  }

  if(dif > q) {
    cout << 0 << endl;
    return 0;
  }

  if(dif%2 != q%2) {
    cout << 0 << endl;
    return 0;
  }

  int pos;
  int neg;

  neg = q - dif;
  neg /= 2;
  pos = dif + neg;
  if(q == 0) {
    cout << (dif == 0) << endl;
    return 0;
  }
  ll num = c(q, pos);
  ll den = total;
  cout << setprecision(10) <<  num/den << endl;

  return 0;
}
