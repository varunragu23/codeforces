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
int cell(VVI& grid, vector<vector<bool>>& vis, int i, int j) {
  if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size()) return 0;
  if(vis[i][j]) return 0;
  if(grid[i][j]) return 0;
  return 1;
}
void dfs(VVI& grid, vector<vector<bool>>& vis, int& cur, int i, int j, int k, int s) {
  if(!cell(grid, vis, i, j)) return;
  vis[i][j] = true;
  if(cur >= s - k) grid[i][j] = 2;
  cur++;
  dfs(grid, vis, cur, i + 1, j, k, s);
  dfs(grid, vis, cur, i, j + 1, k, s);
  dfs(grid, vis, cur, i - 1, j, k, s);
  dfs(grid, vis, cur, i , j - 1, k, s);
}
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("pavelmaze.in", "r", stdin);    
  freopen("pavelmaze.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);


  int n, m;

  cin >> n >> m;
  
  int k;
  cin >> k;

  VVI vals(n, VI(m, 0));

  int s = 0;
  int x, y;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if(c == '#') vals[i][j]++;
      else {s++; x = i; y = j;}
    }
  }
  int cur = 0;
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  if(s)
  dfs(vals, vis, cur, x, y, k, s);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(vals[i][j] == 0) cout << '.';
      if(vals[i][j] == 1) cout << '#';
      if(vals[i][j] == 2) cout << 'X'; 
    }
    cout << endl;
  }

  return 0;
}
