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

vector<vector<pair<bool, int>>> dp(30020, vector<pair<bool, int>>(491, MP(false, 0)));
//int a[30020];
VI a(30020, 0);
int n, d;

int l(int i) {
  return max(d + i - 255, 1);
}

bool bounds(int l, int i) {
  if(l <= 0) return false;
  if(l + i > 30010) return false;
  return true;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("treasurehunter.in", "r", stdin);    
  freopen("treasurehunter.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  

  cin >> n >> d;

  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x]++;
    for(int j = 0; j < 491; j++) {
      dp[x][j].second++;
    } 
  }

  dp[d][255].first = true;




  for(int i = 0; i < 30020; i++) {
    for(int j = 0; j < 491; j++) {
      if(dp[i][j].first == false) continue;
      //case 1: l - 1
      if(bounds(l(j) - 1, i)) {
        dp[i + l(j) - 1][j - 1].second = max(dp[i + l(j) - 1][j - 1].second, dp[i][j].second + a[i + l(j) - 1]);
        dp[i + l(j) - 1][j - 1].first = true;
      }
      //case 2 : l
      if(bounds(l(j), i)) {
        dp[i + l(j)][j].second = max(dp[i + l(j)][j].second, dp[i][j].second + a[i + l(j)]);
        dp[i + l(j)][j].first = true;
      }
      //case 3 : l + 1
      if(bounds(l(j) + 1, i)) {
        dp[i + l(j) + 1][j + 1].second = max(dp[i + l(j) + 1][j + 1].second, dp[i][j].second + a[i + l(j) + 1]);
        dp[i + l(j) + 1][j + 1].first = true;
      }
    }
  }

  int mx = 0;

  for(auto& x: dp) {
    for(auto& y: x) {
      if(y.first)
      mx = max(mx, y.second);
    }  
  }



  cout << mx << endl;



  return 0;
}
