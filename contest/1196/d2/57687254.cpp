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
//  freopen("rgbstring.in", "r", stdin);    
  //freopen("rgbstring.out", "w", stdout); 

  cin.sync_with_stdio(0); cin.tie(0);

  
  int q;
  cin >> q;
  while(q--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    VVI cost(n - k + 1, VI(3, 0));
    vector<string> ch(3);
    ch[0] = "RGB";
    ch[1] = "GBR";
    ch[2] = "BRG";
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < k; j++) {
        cost[0][i] += (s[j] != ch[i][j%3]);
      }
    }

    for(int i = 1; i < n - k + 1; i++) {
      for(int j = 0; j < 3; j++) {
        
        //    cost[i][j] += (s[i + m] != ch[j][m%3]);
        cost[i][j] = cost[i - 1][(j + 2)%3];
        cost[i][j] -= (s[i - 1] != ch[(j + 2)%3][0]);
        cost[i][j] += (s[i + k - 1] != ch[j][(k - 1)%3]);
      }
    }
    int ret = INF;
    for(int i = 0; i < cost.size(); i++) {
      for(int j = 0; j < 3; j++) {
        ret = min(ret, cost[i][j]);
      }
    }
    cout << ret << endl;
  }


  return 0;
}
