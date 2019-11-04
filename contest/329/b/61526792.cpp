/*
ID: varunra2
LANG: C++
TASK: biridianforest
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



bool getcell(int i, int j, vector<string>& g) {
  if(i < 0 or j < 0 or i >= g.size() or j >= g[i].size()) return 0;
  return g[i][j] != 'T';
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("biridianforest.in", "r", stdin);    
  freopen("biridianforest.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int n, m;
  cin >> n >> m;

  VI dx = {0, -1, 0, 1};
  VI dy = {1, 0, -1, 0};

  vector<string> v(n);
  PII start;
  PII end;
  for(int i = 0; i < n; i++) {
    cin >> v[i];
    for(int j = 0; j < m; j++) {
      if(v[i][j] == 'S') start = MP(i, j);
      if(v[i][j] == 'E') end = MP(i, j); 
    }
  }

  VVI dist(n, VI(m, 0));

  vector<vector<bool>> vis(n, vector<bool>(m, false));

  queue<PII> p;
  p.push(end);

  while(!p.empty()) {
    PII s = p.front();
    p.pop();
    for(int i = 0; i < 4; i++) {
      int a, b;
      a = s.x + dx[i];
      b = s.y + dy[i];
      if(!getcell(a, b, v)) continue;
      if(vis[a][b]) continue;
      vis[a][b] = true;
      dist[a][b] = dist[s.x][s.y] + 1;
      p.push(MP(a, b));
    }
  }
  int ret = 0;
  int comp = dist[start.x][start.y];
  for(int i = 0; i < n; i++) {
    for(int j  = 0; j < m; j++) {
      if(dist[i][j] <= comp and v[i][j] >='0' and v[i][j] <= '9' and dist[i][j] != 0) {
        ret += (v[i][j] - '0');
      }
      //cout << dist[i][j] << " ";
    }
    //cout << endl;
  }

  cout << ret << endl;

  

  return 0;
}
