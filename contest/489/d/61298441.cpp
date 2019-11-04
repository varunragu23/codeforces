/*
ID: varunra2
LANG: C++
TASK: controversofbeing
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
  freopen("controversofbeing.in", "r", stdin);    
  freopen("controversofbeing.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int n, m;
  cin >> n >> m;

  VVI adj(n);
  VVI mat(n, VI(n, 0));
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].PB(b);
    mat[a][b] = 1;
  }
  ll ret = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      int cnt = 0;
      for(int k = 0; k < adj[i].size(); k++) {
        int x = adj[i][k];
        if(x == i or x == j) continue;
        cnt += (mat[x][j]);
      }
      ret += (cnt)*(cnt-1)/2; 
      //cout << i << " " << j << "    " << cnt << endl;
    }
  }



  cout << ret << endl;

  return 0;
}
