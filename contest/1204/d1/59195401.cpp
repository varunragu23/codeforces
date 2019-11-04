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
int lonincsub(string& s) {
  int lone = -1;
  int lzero = -1;
  VI dp(s.size(), 1);
  for(int i = 0; i < dp.size(); i++) {
    if(lzero != -1) {
      dp[i] = max(dp[i], dp[lzero] + 1);
    }
    if(s[i] == '1' and lone != -1) {
      dp[i] = max(dp[i], dp[lone] + 1);
    }
    if(s[i] == '0') lzero = i;
    else lone = i;
  }
  return *max_element(dp.begin(), dp.end());
}
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("binarystring.in", "r", stdin);    
  freopen("binarystring.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);


  string s;
  cin >> s;
  int n = s.size();
  


  for(int i = 0; i < n; i++) {
    if(s[i] == '0') continue;

    int a = lonincsub(s);
    s[i] = '0';
    int b = lonincsub(s);
    if(a == b) continue;
    else s[i] = '1';
  }

  cout << s << endl;

  return 0;
}