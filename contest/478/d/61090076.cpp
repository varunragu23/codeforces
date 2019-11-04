/*
ID: varunra2
LANG: C++
TASK: redgreentows
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

int r, g;

ll dp[200010];

int ht;

ll cnt(int x) {
  return x*(x+1)/2;
}



int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("redgreentows.in", "r", stdin);    
  freopen("redgreentows.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  cin >> r >> g;
  MEM(dp, 0);
  for(int i = 0; cnt(i) <= r + g; i++) {
    ht = i;
  }

  dp[0] = 1;

  for(int i = 1; i <= ht; i++) {
    for(int j = r; j >= 0; j--) {
      
      if(j >= i) dp[j] += dp[j - i];
      dp[j] %= MOD;
    }
  }

  ll w = 0;

  for(int i = r; i >= 0; i--) {
    if(cnt(ht) - i <= g) w += dp[i];
    else break;
    w %= MOD;
  } 

  cout << w << endl;

  return 0;
}
