/*
ID: varunra2
LANG: C++
TASK: balrem
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
  freopen("balrem.in", "r", stdin);    
  freopen("balrem.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int n;

  cin >> n;

  VVI vals(n, VI(4));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 3; j++) {
      cin >> vals[i][j];
    }
    vals[i][3] = i;
  }

  sort(vals.begin(), vals.end());
  VI ret;
  while(n > 0) {
    int i = n  - 2;
    if(vals[i][0] != vals[i + 1][0] and i >= 1 and vals[i - 1][0] == vals[i][0]) i--;
    if(vals[i][0] == vals[i + 1][0]) {
      if(vals[i][1] != vals[i + 1][1] and i >= 1 and vals[i - 1][1] == vals[i][1]) i--;
      if(vals[i][1] == vals[i + 1][1]) {
        if(vals[i][2] != vals[i + 1][2] and i >= 1 and vals[i - 1][2] == vals[i][2]) i--;
      }
    }
    ret.PB(vals[i][3] + 1);
    ret.PB(vals[i + 1][3] + 1);
    n -= 2;

    for(int j = i; j < n; j++) {
      vals[j] = vals[j + 2];
    }
  }

  for(int i = 0; i < ret.size(); i+= 2) {
    cout << ret[i] << " " << ret[i + 1] << endl;
  }

  return 0;
}
