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
#define MOD 998244353
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
void fix(long long& a, int n) {
  vector<int> dig;
  while(a) {
    dig.PB(a%10);
    dig.PB(a%10);
    a/=10;
  }
  //reverse(dig.begin(), dig.end());
  long long pw = 1;
  for(int i = 0; i < dig.size(); i++) {
    a+=(pw*dig[i]);
    pw*=10;
    pw = pw%MOD;
    a = a%MOD;

  }
  a*=n;
  a = a%MOD;
  //a = a%MOD
  return;
} 
int main(int argc, char const *argv[]) {
//  freopen("submarine.in", "r", stdin);    
  //freopen("submarine.out", "w", stdout); 

  cin.sync_with_stdio(0); cin.tie(0);


  int n;
  cin >> n;

  vector<long long> vals (n);

  for(int i = 0; i < n; i++) {
    cin >> vals[i];
    fix(vals[i], n);
  }

  long long ret = 0;

  for(int i = 0; i < n; i++) {
    ret += vals[i];
    ret = ret % MOD;
  }

  cout << ret;



  return 0;
}
