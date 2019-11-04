/*
ID: varunra2
LANG: C++
TASK: cowseq
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

#define deb(x) cerr << #x << " = " << x << endl;


// util functions

#pragma endregion

vector<ll> vals(200200, 0);
vector<ll> add(200200, 0);
  

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("cowseq.in", "r", stdin);    
  freopen("cowseq.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;

  

  
  ll sum = 0;
  ld tot = 1;
  for(int i = 0; i < n; i++) {
    char t;
    cin >> t;
    if(t == '1') {
      int a, x;
      cin >> a >> x;
      sum += 1LL * a*x;

    
      add[a] += x;
    }
    else if(t == '2') {
      ll d;
      cin >> d;
      
      sum += d;
      vals[++tot] = d;
      add[tot] = 0;
    }
    else {
      sum -= (add[tot] + vals[tot]);
      //cout << "removing " << (add[tot] + vals[tot]) << endl;
      add[tot - 1] += add[tot];
      //add[tot] = 0;
      //vals[tot] = 0;
      tot--;
    }
    float ret = sum;


  ret /= tot;

  printf("%.12lf\n", 1. * ret);
  }

 

  return 0;
}
