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
//  freopen("Ddivmul.in", "r", stdin);    
  //freopen("Ddivmul.out", "w", stdout); 

  cin.sync_with_stdio(0); cin.tie(0);

  
  int n;

  cin >> n;

  vector<long long> s(n);
  map<long long, int> freq;
  map<long long, long long> next;
  map<long long, long long> prev;

  vector<long long> ret(n);
  //if it is first, it will hold 0

  for (int i = 0; i < n; i++) {
    cin >> s[i];
    freq[s[i]]++;
  }

  for (int i = 0; i < n; i++) {
    if (freq[s[i] * 2]) {
      next[s[i]] = s[i] * 2;
    }
    else if (!(s[i] % 3) && freq[s[i] / 3]) {
      next[s[i]] = s[i] / 3;
    }
    else {

      //cout << s[i] << "is at the end" << endl;
    }
    if (freq[s[i] * 3]) {
      prev[s[i]] = s[i] * 3;
    }
    else if (!(s[i] % 2) && freq[s[i] / 2]) {
      prev[s[i]] = s[i] / 2;
    }
    else {
      prev[s[i]] = s[i];
      ret[0] = s[i];
      //cout << s[i] << "is at the beginning" << endl;
    }

  }


  //cout << ret[0] << endl;

  for (int i = 1; i < n; i++) {
    //we need to find ret[i]
    //how do we go about doing this?
    //it is equal to the next element of the previous val

    //aight lets do it fam

    ret[i] = next[ret[i - 1]];



  }
  //yo need to print everything
/*
  for (auto x: freq) {
    cout << x.first << " : " << x.second << endl;
  }
  cout << endl << endl;
  for (auto x: next) {
    cout << x.first << " : " << x.second << endl;
  }
  cout << endl << endl;
  for (auto x: prev) {
    cout << x.first << " : " << x.second << endl;
  }
  cout << endl << endl;

*/
  for (auto x: ret) {
    cout << x << " ";
  }
// printvi(ret);



  return 0;
}
