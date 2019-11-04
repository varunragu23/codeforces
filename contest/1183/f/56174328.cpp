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
int a[200005];
/* void logger() {
  cout << "Good" << endl;
}
*/
int main(int argc, char const *argv[]) {
  //freopen("topcoder.in", "r", stdin);    
  //freopen("topcoder.out", "w", stdout); 

  cin.sync_with_stdio(0); cin.tie(0);

  int q;
  //scanf("%d", &q);
  scanf("%d", &q);
  //cout << q << endl;
  for(int m = 0; m < q; m++) {
    int n;
    scanf("%d", &n);
    //logger();
    for(int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    //logger();
    sort(a + 1, a + 1 + n);
    n = unique(a + 1, a + 1 + n) - a - 1;
    //logger();
    int ans = a[n];
    //logger();
    for(int i = n; i >= 2; i--) {
      for(int j = i - 1; j >= 1; j--) {
        if(a[i]%a[j] && a[j]%a[i]) {
          ans = max(ans, a[i] + a[j]);
          break;
        }
      }
    }
    //logger();
    for(int i = n; i >= 3 && (a[i] + a[i - 1] + a[i - 2]) > ans; i--) {
      for(int j = i - 1; j >= 2 && (a[i] + a[j] + a[j - 1]) > ans; j--) {
        
        if(a[i]%a[j]) {
          //bool next = false;
          for(int k = j - 1; k >= 1 && (a[i] + a[j] + a[k]) > ans; k--) {
            if(a[i]%a[k] && a[j]%a[k]) {
              ans = max(ans, a[i] + a[j] + a[k]);
              //next = true;
              break;
            }
          }
          //if(next) break;
        }
      }
    //logger();
    }
    printf("%d\n", ans);
  }

  
  return 0;
}
