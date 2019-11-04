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
typedef long long ll;

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
bool works(int be, int ee, int howmanye, int& opse, MPII& freq) {
  ll b = be;
  ll e = ee;
  ll howmany = howmanye;
  ll ops = opse;
  ll cost = (e - b)*howmany;
  if(cost > ops) {
    ll end = ops/(howmany) + b;
    freq[be] = 0;
    freq[end] = howmanye;
    return false;
  }
  else {
    opse -= cost;
    freq[ee] += howmanye;
    freq[be] = 0;
    return true;
  }
}
int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("maximmedian.in", "r", stdin);    
  freopen("maximmedian.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);


  int n;
  cin >> n;

  int k;
  cin >> k;

  VI vals(n);

  for(int i = 0; i < n; i++) {
    cin >> vals[i];
  }

  sort(vals.begin(), vals.end());

  VI v;

  for(int i = n/2; i < n; i++) {
    v.PB(vals[i]);
  }

  MPII freq;
  n = (int)v.size();
  for(int i = 0; i < n; i++) {
    freq[v[i]]++;
  }

  auto last = unique(v.begin(), v.end());

  v.erase(last, v.end());

  n = (int)v.size();

  for(int i = 0; i < n; i++) {
    int end = INT_MAX;
    if(i < n - 1) end = v[i + 1];
    if(!works(v[i], end, freq[v[i]], k, freq)) {
      break;
    }
    //cout << v[i] << ": " << freq[v[i]] << endl;
  }

  for(auto& x: freq) {
    //cout << x.first << ": " << x.second << endl;
    if(x.second) {
      cout << x.first;
      return 0;
    }
  }

  return 0;
}
