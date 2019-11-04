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

int n;
int r;
int dp[150][60600];
const int c = 60600;

static bool comp(PII& a, PII& b) {
  return a.first + a.second > b.first + b.second;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("compproj.in", "r", stdin);    
  freopen("compproj.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  cin >> n >> r;

  VII pos;
  VII neg;

  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if(b > 0) {
      pos.PB(MP(a, b));
    }
    else {
      neg.PB(MP(a, b));
    }
  }

  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end(), comp);

  int ans = 0;

  for(int i = 0; i < pos.size(); i++) {
    if(r < pos[i].first) continue;
    else {ans++; r += pos[i].second;}
  }

  for(int i  = 0; i <= neg.size(); i++) {
    for(int j = 0; j < c; j++) {
      dp[i][j] = -1;
    }
  }
  int ret = 0;
  dp[0][r] = 0;
  for(int i = 0; i < neg.size(); i++) {
    for(int j = 0; j < c; j++) {
      if(dp[i][j] == -1) continue;
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if(j >= neg[i].first and j + neg[i].second >= 0) {
        dp[i + 1][j + neg[i].second] = max(dp[i + 1][j + neg[i].second], dp[i][j] + 1);
      }
    }
  }
  int mx = 0;
  for(int i = 0; i < c; i++) {
    mx = max(mx, dp[neg.size()][i]);
  }

  cout << mx + ans << endl;

  return 0;
}
