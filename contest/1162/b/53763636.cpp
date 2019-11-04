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
bool help(VVI& m, int r, int c, int dx, int dy) {
  if(r < 0 || c < 0 || r >= m.size() || c >= m[0].size()) {
    return true;
  }
  if (dx > 0 || dy > 0) return (m[r][c] > m[r - dx][c - dy]);
  return (m[r][c] < m[r - dx][c - dy]);
}
bool good(VVI& m, int r, int c) {
  return (help(m, r + 1, c, 1, 0) && help(m, r, c + 1, 0, 1) && help(m, r - 1, c, -1, 0) && help(m, r, c - 1, 0, -1));
/*
  if (r >= 0 && r < m.size() && c >= 0 && c < m[0].size())) 

//
  if(r == 0) {
    if(c!=0) {
    if (!(m[r][c] > m[r][c - 1])) return false; }
  }
  else if(c == 0) {
    if (!(m[r][c] > m[r - 1][c])) {
      return false;
    }
  }
  else if (!((m[r][c] > m[r - 1][c]) && (m[r][c - 1] <= m[r][c]))) {
    return false;
  }
  if (r == m.size() - 1) {
    if (c == m[0].size() - 1) {
      return true;
    }
    return (m[r][c + 1] > m[r][c]);
  }
  if(c == m[0].size()) {
    return(m[r + 1][c] > m[r][c]);
  }
  return ((m[r + 1][c] > m[r][c]) && (m[r][c + 1] > m[r][c]));
  //return ((m[r][c] > m[r - 1][c]) && (m[r][c - 1] <= m[r][c]));
  */
}
void pprint(bool i) {
  cout << (i ? "Possible" : "Impossible");
  return;
}
bool canf(VVI& m1, VVI& m2, int i, int j) {
  if (i < 0 || j < 0) return false;
  swap(m1[i][j], m2[i][j]);
  if (good(m1, i, j) && good(m2, i, j)) {
    return true;
  }
  swap(m1[i][j], m2[i][j]);
  return false;
}
bool canflip(VVI& m1, VVI& m2, int i, int j) {
  //assuming m1[i][j] bad
  if(good(m1, i, j)) return true;
  //cout << "IT is bad, we need to flip " << m1[i][j] << " and " << m2[i][j] << endl;
  swap(m1[i][j], m2[i][j]);
  if(good(m1, i, j) && good(m2, i, j)) {
    //cout << "Phew, we are saved" << endl;

    return true;
  } 
  return (canf(m1, m2, i - 1, j) || canf(m1, m2, i, j - 1));

}


int main(int argc, char const *argv[]) {
//  freopen("Bswap.in", "r", stdin);    
  //freopen("Bswap.out", "w", stdout); 

  cin.sync_with_stdio(0); cin.tie(0);

  
  int n, m;

  cin >> n >> m;

  VVI m1(n, VI(m));
  VVI m2(n, VI(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> m1[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> m2[i][j];
      if(m2[i][j] < m1[i][j]) {
        swap(m2[i][j], m1[i][j]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if(!good(m1,i,j) || !good(m2,i,j)) {
        pprint (false);
        return 0;
      }
    }
  }
  pprint(true);

  return 0;
}
