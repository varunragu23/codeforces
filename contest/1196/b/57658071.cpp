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
//  freopen("suboddsum.in", "r", stdin);    
  //freopen("suboddsum.out", "w", stdout); 

  cin.sync_with_stdio(0); cin.tie(0);

  int q;
  cin >> q;

  while(q--) {
    int n, k;
    cin >> n >> k;
    VI vals(n);
    for(int i = 0; i < n; i++) {
      cin >> vals[i];
      vals[i] = vals[i]%2;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
      cnt += vals[i];
    }
    if(cnt < k) {
      cout << "NO" << endl;
      continue;
    }
    if(cnt%2 != k%2) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
      if(k == 1) {
        cout << n << endl;
        break;
      }
      if(vals[i]) {
        cout << i + 1 << " ";
        k--;
      }
    }
  }
  
  return 0;
}
