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

string s;
string t;

string w(char& a, char& b, char& c) {
  string s1 = "";
  string s2 = "";
  for(int i = 0; i < n; i++) {
    s1.append(1,a);
    s1.append(1,b);
    s1.append(1, c);
  }
  for(int i = 0; i < n; i++) {
    s2.append(1, a);
  }
  for (int i = 0; i < n; i++) {
    s2.append(1, b);
  }
  for (int i = 0; i < n; i++) {
    s2.append(1, c);
  }
  bool c1 = true;
  bool c2 = true;
  for(int i = 0; i < 3*n - 1; i++) {
    if(s1[i] == s[0] and s1[i + 1] == s[1]) c1 = false;
    if(s1[i] == t[0] and s1[i + 1] == t[1]) c1 = false;
    if (s2[i] == s[0] and s2[i + 1] == s[1]) c2 = false;
    if (s2[i] == t[0] and s2[i + 1] == t[1]) c2 = false;
  }
  string ret = "";
  if(c1 == true) return s1;
  if(c2 == true) return s2;
  return ret;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("twosmallstrings.in", "r", stdin);    
  freopen("twosmallstrings.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  cin >> n;

  cin >> s >> t;



  char a = 'a';
  char b = 'b';
  char c = 'c';

  vector<string> ret(6);
  ret[0] = w(a, b, c);
  ret[1] = w(a, c, b);
  ret[2] = w(b, a, c);
  ret[3] = w(b, c, a);
  ret[4] = w(c, b, a);
  ret[5] = w(c, a, b);

  for(int i = 0; i < 6; i++) {
    if(ret[i] != "") {
      cout << "YES" << endl;
      cout << ret[i] << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
