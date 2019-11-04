/*
ID: varunra2
LANG: C++
TASK: fallinganvils
*/
#pragma region Headers, define, typedef
#include<bits/stdc++.h>

using namespace std;
#ifdef DEBUG
#include <debug.h>
#endif

#define EPS 1e-9
#define IN(A, B, C) assert(B <= A && A <= C)
#define INF (int)1e9
#define MEM(a, b) memset(a, (b), sizeof(a))
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define x first
#define y second

const double PI = acos(-1.0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef map<int, int> MPII;
typedef multiset<int> MSETI;
typedef set<int> SETI;
typedef set<string> SETS;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<string> VS;

#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// util functions

#pragma endregion


int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("fallinganvils.in", "r", stdin);    
  freopen("fallinganvils.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;

  while(t--) {
    ld a, b;
    cin >> a >> b;
    ld ret = 0.50000000;
    if(b == 0) {
      cout << 1 << endl;
      continue;
    }
    if(a == 0) {
      cout << ret << endl;
      continue;
    }
    if(b*4 < a) {
      // trapezoid
      ld base1, base2, height;
      base1 = a; // bottom
      base2 = a - 4*b; // top
      height = b;
      ld area = (base1 + base2)/2 * height;
      area /= (a*b*2);
      ret += area;
    }
    else {
      // triangle
      ld base;
      ld height;
      base = a;
      height = a/4;
      ld area = base*height/2;
      area /= (a*b*2);
      ret += area;
    }
    cout << setprecision(15) << ret << endl;
  }

  return 0;
}
