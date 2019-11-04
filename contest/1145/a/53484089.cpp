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
void toprint(VVI& grid) {
  for (auto& x : grid) {
    for (auto& y : x) {
      cout << y << " ";
    }
    cout << endl;
  }
}
bool onBound(vector<vector<int> >& grid, int i, int j) {
  if (i == 0 || j == 0) {
    return true;
  }
  if (i == grid.size() - 1 || j == grid[0].size() - 1) {
    return true;
  }
  return false;
}
bool crossBound(vector<vector<int> >& grid, int i, int j) {
  if (i <= -1 || j <= -1) {
    return true;
  }
  if (i >= grid.size() || j >= grid[0].size()) {
    return true;
  }
  return false;
}
bool changecol(VVI& grid, int i, int j, int color) {
  if (onBound(grid, i, j)) {
    //grid[i][j] = -grid[i][j];
    return true;
  }
  
    if (grid[i + 1][j] != grid[i][j] && grid[i + 1][j] != -grid[i][j]) {
      //grid[i][j] = -grid[i][j];
      return true;
    }
  
  
    if (grid[i - 1][j] != grid[i][j] && grid[i - 1][j] != -grid[i][j]) {
      return true;
    }

  
    if (grid[i][j + 1] != grid[i][j] && grid[i][j + 1] != -grid[i][j]) {
      return true;
    } 
  
    if (grid[i][j - 1] != grid[i][j] && grid[i][j - 1] != -grid[i][j]) {
      return true;
    }
  
  return false;
}
void dfs(vector<vector<int> >& grid, int i, int j, int color,
         vector<vector<bool> >& vis, int pcolor) {
    if (crossBound(grid, i, j) || pcolor != grid[i][j]) {
      return;
    }
    if (vis[i][j]) {
      return;
    }
    vis[i][j] = true;
    int cur = grid[i][j];
    
    
    dfs(grid, i + 1, j, color, vis, cur);
    dfs(grid, i - 1, j, color, vis, cur);
    dfs(grid, i, j + 1, color, vis, cur);
    dfs(grid, i, j - 1, color, vis, cur);

    if (changecol(grid, i, j, color)) {
      grid[i][j] = -grid[i][j];
    }
}

int toChange(string& s) {
  int ret = abs(s[0] - 'A');
  ret += abs(s[1] - 'C');
  ret += abs(s[2] - 'T');
  ret += abs(s[3] - 'G');
  return ret;
}
bool isSorted(VI& thanos) {
  int n = thanos.size();
  for (int i = 0; i < n - 1; i++) {
    if (thanos[i] > thanos[i + 1]) {
      return false;
    }
  }
  return true;
}
int remhalf(VI& thanos, int& maxi) {
  if (isSorted(thanos)) {
    maxi = thanos.size();
    return maxi;
  }
  VI left(thanos.begin(), thanos.begin() + thanos.size()/2);
  VI right(thanos.begin() + thanos.size()/2, thanos.end());
  return max(remhalf(left, maxi), remhalf(right, maxi));
}

int main(int argc, char const* argv[]) {
//  freopen("leetcodehelp.in", "r", stdin);
  //freopen("leetcodehelp.out", "w", stdout);

  cin.sync_with_stdio(0);
  cin.tie(0);

  int n;

  cin >> n;

  VI thanos(n);

  for (int i = 0; i < n; i++) {
    cin >> thanos[i];
  }
  int maxi = 0;
  cout << remhalf(thanos, maxi);
}
