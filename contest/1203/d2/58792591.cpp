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

void subsequences(string& s, string& t, VI& pref, VI& suf) {
  int n = s.size();
  int m = t.size();


  int p1 = 0;
  int p2 = 0;


  while(p1 < n) {
    if(s[p1] == t[p2]) {
      pref[p2] = p1;
      p2++;
    }
    p1++;
    if(p2 == m) break;
  }

  p1 = n - 1;
  p2 = m - 1;

  while(p1 >= 0) {
    if(s[p1] == t[p2]) {
      suf[p2] = p1;
      p2--;
    }
    p1--;
    if(p2 <= -1) break;
  }

  return;

}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("remsubstring.in", "r", stdin);    
  freopen("remsubstring.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);


  string s;
  string t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  VI pref(m), suf(m);

  subsequences(s, t, pref, suf);

  int mx = 0;
  mx = max(mx, suf[0]);
  mx = max(mx, n - pref[m - 1] - 1);
  for(int i = 0; i < m - 1; i++) {
    mx = max(mx, suf[i + 1] - pref[i] - 1);
  }

  cout << mx << endl;



  return 0;
}
