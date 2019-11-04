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

 vector<bool> sieve(int n) {
  // Create a boolean array "prime[0..n]" and initialize
  // all entries it as true. A value in prime[i] will
  // finally be false if i is Not a prime, else true.
  vector<bool> prime(n + 1, true);
  //memset(prime, true, sizeof(prime));

  for (int p = 2; p * p <= n; p++) {
    // If prime[p] is not changed, then it is a prime
    if (prime[p] == true) {
      // Update all multiples of p greater than or
      // equal to the square of it
      // numbers which are multiple of p and are
      // less than p^2 are already been marked.
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  return prime;
  
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("tprime.in", "r", stdin);    
  freopen("tprime.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);


  vector<bool> prime = sieve(1e6);

  map<ll, int> s;

  for(ll i = 2; i <= 1e6; i++) {
    if(prime[i]) s[i*i]++;
  }

  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    if(s[a]) {
      cout << "YES" << endl;
    }
    else cout << "NO" << endl;
  }

  

  return 0;
}
