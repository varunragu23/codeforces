/*
ID: varunra2
LANG: C++
TASK: innandima
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

vector<vector<char>> g(1010, vector<char>(1010, 0));
VVI e(1000010);
VI dp(1000010);
int n, m;
VI dx = {0, 1, 0, -1};
VI dy = {1, 0, -1, 0};

bool bounds(int x, int y) {
  if(x < 0 or y < 0) return false;
  if(x >= n or y >= m) return false;
  return true;
}

int dfs(int x) {
  int y, ret = 0;
  dp[x] = -2;
  for(int i = 0; i < e[x].size(); i++) {
    y = e[x][i];
    if(dp[y] == -2) return dp[x] = INF;
    if(dp[y] == -1) dfs(y);
    ret = max(ret, dp[y]);
  }
  return dp[x] = ret + 1;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("innandima.in", "r", stdin);    
  freopen("innandima.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  map<int, int> abc;
  abc['D'] = 1;
  abc['I'] = 2;
  abc['M'] = 3;
  abc['A'] = 4;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      for(int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        //new pos to move to
        if(!bounds(x, y)) continue;
        if((abc[g[i][j]])%4 + 1 == abc[g[x][y]]) e[i*m + j].PB(x*m + y); 
        
      }
      dp[i*m + j] = -1;
    }
  }

  int mx = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(g[i][j] == 'D') {
        mx = max(mx, dfs(i*m + j));
      }
    }
  }

  if(mx > n*m) cout << "Poor Inna!" << endl;
  else if(mx < 4) cout << "Poor Dima!" << endl;
  else cout << mx/4 << endl;

  return 0;
}
