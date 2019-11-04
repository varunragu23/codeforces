/*
ID: varunra2
LANG: C++
TASK: icecave
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

int x;
int y;
int xx1;
int yy1;

bool pr = false;

bool gd(int i, int j, VVI& vals) {
  if(i >= n or j >= m or j < 0 or i < 0) return false;
  return vals[i][j] == 0;
}

 
VI dx = {1, -1, 0, -0};
VI dy = {0, 0, 1, -1};


void dfs(int i, int j, VVI& vals, vector<vector<int>>& used) {
  
  used[i][j] = 1;

  for(int k = 0; k < 4; k++) {
    int nx = i + dx[k];
    int ny = j + dy[k];
    if(!gd(nx, ny, vals) and ((nx != xx1) or (ny != yy1))) continue;
    //cout << nx << " " << ny << " " <<  k << endl;
    if(used[nx][ny]) continue;
    dfs(nx, ny, vals, used);
  }

  return;

}


int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("icecave.in", "r", stdin);    
  freopen("icecave.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;

  VVI vals(n, VI(m));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if(c == '.') vals[i][j] = 0;
      else vals[i][j] = 1;
    }
  }

  cin >> x >> y >> xx1 >> yy1;
  x--;
  y--;
  xx1--;
  yy1--;
  vals[x][y] = 0;
  if(x == xx1 and y == yy1) {
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(gd(nx, ny, vals)) cnt++; 
    }
    if(cnt >= 1) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
    return 0;
  }
  vector<vector<int>> vis(n, vector<int>(m, 0));

  dfs(x, y, vals, vis);

  bool ok = false;

  for(int i = 0; i < 4; i++) {
    int nx = xx1 + dx[i];
    int ny = yy1 + dy[i];
    if(!gd(nx, ny, vals)) continue;
    
    if(vis[nx][ny]) ok = true;
  }
  if(!ok) {
    cout << "NO" << endl;
    return 0;
  }

  if(vals[xx1][yy1]) {
    cout << "YES" << endl;
    return 0;
  }
  int cnt = 0;
  for(int i = 0; i < 4; i++) {
    int nx, ny;
    nx = xx1 + dx[i];
    ny = yy1 + dy[i];
    if(gd(nx, ny, vals)) cnt++;
  }

  if(cnt > 1) {
    cout << "YES" << endl;
  }
  else cout << "NO" << endl;

  //cout << "NO" << endl;
  

  return 0;
}
