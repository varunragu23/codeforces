/*
ID: varunra2
LANG: C++
TASK: workingout
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

  int n, m;


int getc(int i, int j, VVI& g) {
  if(i < 0 or j < 0 or i >= n or j >= m) return 0;
  return g[i][j];
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("workingout.in", "r", stdin);    
  freopen("workingout.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;

  VVI vals(n + 3, VI(m + 3));

  VVI a1(n + 3, VI(m + 3, 0)), a2(n + 3, VI(m + 3, 0)), b1(n + 3, VI(m + 3, 0)), b2(n + 3, VI(m + 3, 0));

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> vals[i][j];
    }
  }
//1
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      a1[i][j] = vals[i][j];
      a1[i][j] += max(a1[i-1][j], a1[i][j - 1]);
      //a1[i][j] += getc(i, j - 1, a1);
    }
  }
//2
  for(int i = n; i >= 1; i--) {
    for(int j = m; j >= 1; j--) {
      a2[i][j] = vals[i][j];
      a2[i][j] += max(a2[i + 1][j],a2[i][j + 1]);
      //a2[i][j] += getc(i, j + 1, a2);
    }
  }
//3
  for(int i = 1; i <= n; i++) {
    for(int j = m; j >= 1; j--) {
      b1[i][j] = vals[i][j];
      b1[i][j] += max(b1[i - 1][j], b1[i][j + 1]);
    }
  }
//4
  for(int i = n; i >= 1; i--) {
    for(int j = 1; j <= m; j++) {
      b2[i][j] = vals[i][j];
      b2[i][j] += max(b2[i + 1][j], b2[i][j - 1]);
    }
  }

//calc
  ll ret = 0;
  for(int i = 2; i < n; i++) {
    for(int j = 2; j < m; j++) {
      ll cur1, cur2;
      cur1 = (a1[i - 1][j] + a2[i + 1][j] + b2[i][j - 1] + b1[i][j + 1]);
      cur2 = (a1[i][j - 1] + a2[i][j + 1] + b2[i + 1][j] + b1[i - 1][j]);
      ll cur = max(cur1, cur2);
      ret = max(ret, cur);
      //cout << cur << " ";
    }
    //cout << endl;
  }

  cout << ret << endl;

  

  return 0;
}
