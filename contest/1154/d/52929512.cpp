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
  //freopen("Drob.in", "r", stdin);
  //freopen("Drob.out", "w", stdout);

  cin.sync_with_stdio(0);
  cin.tie(0);

  int a, b, n;

  cin >> n >> b >> a;

  int cap = a;

  vector<int> sun(n);

  int traveled = 0;

  for (int i = 0; i < n; i++) {
    cin >> sun[i];
  }

  while (!(b == 0 && a == 0) && (traveled < n)) {
    // curr spot either 0 or 1
    // if 0, use

    if (sun[traveled] == 0) {
      if (a == 0) {
        b--;
        //cout << "case 1      ";
        // traveled++;
      } else {
        a--;
        //cout << "case 2      ";
        // traveled++;
      }

    } else {
      if (b == 0 || a == cap) {
        a--;
        //cout << "case 3      ";
      }

      else {
        b--;
        a++;
        //cout << "case 4      ";
      }

     }
     traveled++;

     //cout << "b is equal to : " << b << " a is equal to : " << a
    //      << " we have currently taken " << traveled << "steps" << endl;
  }

  cout << traveled;
  cout << flush;

  return 0;
}
