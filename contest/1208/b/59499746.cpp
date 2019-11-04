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
#ifndef ONLINE_JUDGE
  freopen("uniqueness.in", "r", stdin);    
  freopen("uniqueness.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);


  int n;
  cin >> n;

  VI vals(n);

  for(int i = 0; i < n; i++) {
    cin >> vals[i];
  }

  MPII freq;
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    freq[vals[i]]++;
    if(freq[vals[i]] == 2) cnt++; 
  }
  
  if(cnt == 0) {cout << 0 << endl; return 0;}
  
  MPII cur;
  int mn = INT_MAX;
  int k;
  for(k = n - 1; k >= 0; k--) {
    cur[vals[k]]++;
    if(cur[vals[k]] >= 2) {
      mn = min(mn, k + 1);
      break;
    }
  }
  for(; k < n; k++) cur[vals[k]]--;
  for(int i = 0; i < n - 1; i++) {
    cur[vals[i]]++;
    if(cur[vals[i]] >= 2) break;
    int j;
    for (j = n - 1; j > i; j--) {
      cur[vals[j]]++;
      if(cur[vals[j]] >= 2) {
        if(mn > j - i) {
          mn = j - i;
          //cout << j << " " << i << endl;
        }
        break;
      }
    }
    for(; j < n; j++) {
      cur[vals[j]]--;
    }
    //cout << cur[7] << endl;
  }

  cout << mn << endl;

  return 0;
}
