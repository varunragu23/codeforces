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

void qry(vector<ll>& pref, int l, int r, ll cnt) {
  pref[l] += cnt;
  if(r < pref.size() - 1) {
    pref[r + 1] -= cnt;
  }
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("gregarray.in", "r", stdin);    
  freopen("gregarray.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> vals(n);

  for(int i = 0; i < n; i++) {
    cin >> vals[i];
  }

  vector<vector<ll>> q1(m, vector<ll> (3));

  for(int i = 0; i < m; i++) {
    for(int j = 0; j < 3; j++) {
      cin >> q1[i][j];
      if(j <= 1) q1[i][j]--;
    }
  }

  vector<vector<ll>> q2(k, vector<ll> (2));

  for(int i = 0; i < k; i++) {
    for(int j = 0; j < 2; j++) {
      cin >> q2[i][j];
      q2[i][j]--;
    }
  }

  vector<ll> pref(n, 0);

  vector<ll> pref1(m, 0);

  for(int i = 0; i < k; i++) {
    qry(pref1, q2[i][0], q2[i][1], 1);
  }

  for(int i = 1; i < m; i++) {
    pref1[i] += pref1[i - 1];
  }

  for(int i = 0; i < m; i++) {
    q1[i][2] *= pref1[i];
  }

  for(int i = 0; i < m; i++) {
    qry(pref, q1[i][0], q1[i][1], q1[i][2]);
  }
  vals[0] += pref[0];
  for(int i = 1; i < n; i++) {
    pref[i] += pref[i - 1];
    vals[i] += pref[i];
  }

  for(int i = 0; i < n; i++) {
    cout << vals[i] << " ";
  }
  cout << endl;

  
  return 0;
}
