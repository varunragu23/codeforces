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
  for_each(v.begin(), v.end(), [](long long i) -> void { cerr << i << ","; }); \
  cerr << endl;
/*
string s;
int n;
int ret = 0;
void delchar(int& i) {
  if(i < n){
  --n;
  s.erase(s.begin() + i);
  ++ret;
  --i;
  --i;
  }
  else delchar(i - 1);
}
bool bad(int& i) {
  if((i + 1) < s.size()) {
    ++i;
    return (s[i] == s[i + 1]);
  }
  ++i;
  return false;
}*/
int countdivs(long long n) {
  int ret = 0;
  long long i;
  for (i = 2; (i*i) <= n; i++) {
    if(!(n%i)) ret += 2;
  }
  --i;
  if(i*i == n) --ret;
  //cout << n << " has " << ret << " divisors " << endl;
  return ret;
}


int main(int argc, char const *argv[]) {
//  freopen("Aoperation.in", "r", stdin);    
  //freopen("Aoperation.out", "w", stdout); 

  cin.sync_with_stdio(0); cin.tie(0);

  //long long a = 10;
  //cout << countdivs(10ll) << " " << countdivs(2ll) << endl;
  
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    int n;
    cin >> n;
    vector<long long> divs(n);
    for (int j = 0; j < n; j++) {
      cin >> divs[j];
    }
    //printvi(divs);
    sort(divs.begin(), divs.end());
    long long num = divs[0]*divs[n - 1];
    long long ret = num;
    for (int i = 1; i < n - 1; i++) {
      if((divs[i]*divs[n-i-1] != num)) {
        ret = -1;
        //cout << "making ret a -1 in testcase " << i << endl;
        break;
      }
    }
    if(countdivs(num) != n) ret = -1;
    cout << ret << endl;// << " and the projected number is " << num << endl;
    //cout << "Here are my divisors" << endl;
    //printvi(divs);
    //co/ut << endl << endl;
  } 
/*
  for (int i = 1; i <= 100; i++) {
    cout << i << " , " << sieve[i] << endl;
  }
*/
  /*cin >> n;

  
  cin >> s;
  
  for (int i = 0; i < n; i++) {
    if(!bad(i)) delchar(i);
  }
  if(n%2) delchar(n - 1);
  cout << ret << endl << s;
  */
  return 0;

}
