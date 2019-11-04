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
bool getcell(vector<vector<bool>>& b, int i, int j) {
  if(i >= b.size() || j >= b[0].size() || i < 0 || j < 0) return false;
  return b[i][j];
}
bool isPlus(vector<vector<bool>>& b, int i, int j) {
  return getcell(b, i + 1, j) && getcell(b, i - 1, j) && getcell(b, i, j + 1) && getcell(b, i, j - 1);
}
int genPlus(vector<vector<bool>>& b, int i, int j) {
  //vector<int> ret(4);
  int ret = 0;
  int x, y;
  x = i;
  y = j;
  while(getcell(b, x + 1, y)) {
    ++x;
    ++ret;
  }
  x = i;
  y = j;
  while (getcell(b, x - 1, y)) {
    --x;
    ++ret;
  }
  x = i;
  y = j;
  while (getcell(b, x, y + 1)) {
    ++y;
    ++ret;
  }
  x = i;
  y = j;
  while (getcell(b, x, y - 1)) {
    --y;
    ++ret;
  }
  return ret;
}

int main(int argc, char const *argv[]) {
//  freopen("Filling.in", "r", stdin);    
  //freopen("Filling.out", "w", stdout); 

  cin.sync_with_stdio(0); cin.tie(0);

  
  int h, w;
  cin >> h >> w;
  int cnt = 0;
  vector<vector<bool>> there(h, vector<bool> (w));

  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      char c;
      cin >> c;
      there[i][j] = (c == '*');
      cnt += there[i][j];
    }
  }

  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(there[i][j] && isPlus(there, i, j)) {
        int g = genPlus(there, i, j);
        if(g + 1 == cnt) {
          cout << "YES";
          return 0;
        }
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "NO";

  return 0;
}
