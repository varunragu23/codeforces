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
//  freopen("CStoT.in", "r", stdin);    
  //freopen("CStoT.out", "w", stdout); 

  cin.sync_with_stdio(0); cin.tie(0);

  int kkk;
  cin >> kkk;
  while(kkk--) {
    string s, t, p;
    cin >> s >> t >> p;
    if(s.size() > t.size()) {
      cout << "NO" << endl;
      continue;
    }
    bool brk = false;
    if(s.size() == t.size()) {
      cout << (s==t ? "YES" : "NO") << endl;
      continue;
    }
    int p1 = 0;
    int p2 = 0;
    while(p1 < s.size() and p2 < t.size()) {
      if(s[p1] == t[p2]) ++p1;
      ++p2;
      if(p1 == s.size()) break;
      if(p2 == t.size()) brk = true;
    }
    if(brk) {
      cout << "NO" << endl;
      continue;
    }
    map<char, int> freqs;
    map<char, int> freqt;
    map<char, int> freqp;
    for(int i = 0; i < s.size(); i++) {
      freqs[s[i]]++;
    }
    for (int i = 0; i < t.size(); i++) {
      freqt[t[i]]++;
    }
    for (int i = 0; i < p.size(); i++) {
      freqp[p[i]]++;
    }
    for(auto& x: freqt) {
      if(x.second > freqs[x.first] + freqp[x.first]) {
        brk = true;
        break;
      }
    }
    if(brk) {
      cout << "NO" << endl;
    }
    else cout << "YES" << endl;
  }

  return 0;
}
