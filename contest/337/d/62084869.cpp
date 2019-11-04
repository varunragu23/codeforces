#include <bits/stdc++.h>
#define pb push_back
#define ers erase
#define ins insert
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
#define kill(x) return cout << x, 0;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpl;
 
const ld Pi = 3.14159265359;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll N = 2e5 + 10;
const ll INF = 1e18;
const ll LOG = 20;
ll dp1[N], n ,v, u, q, m;
pll dp[N];
vl g[N];
vl node;
void DFS(ll v, ll p = 0){
	vl dp2;
	for (auto u:g[v]){
		if (u == p) continue;
		DFS(u, v);
		dp2.pb(dp[u].F);
	}
	dp2.pb(-1), dp2.pb(-1);
	ll tah = dp2.size() - 1;
	sort(all(dp2));
	//cout << v << ' ' << dp2[tah] << ' ' << dp2[tah - 1] << '\n';
	if (dp2[tah] != -1){
		dp[v].S = dp[v].F;
		dp[v].F =  dp2[tah] + 1;
	}if (dp2[tah - 1] != -1){
		dp[v].S = dp2[tah - 1] + 1;
	}
}
 
void DFS1(ll v, ll p = 0){
	if (p != 0){
		if (dp1[p] != -1){
			dp1[v] = dp1[p] + 1;
		}
		if (dp[p].F == dp[v].F + 1){
			if (dp[p].S != -1){
				dp1[v] = max(dp1[v], dp[p].S + 1);
			}
		}else if(dp[p].F != -1){
			dp1[v] = max(dp1[v], dp[p].F + 1);
		}
	}
	for (auto u:g[v]){
		if (u == p) continue;
		DFS1(u, v);
	}
}
 
 
 
int main(){
	IOS;
	memset(dp, -1, sizeof dp);
	memset(dp1, -1, sizeof dp1);
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++){
		cin >> v;
		node.pb(v);
		dp[v].F = 0;
		dp1[v] = 0;
	}
	
	//cout << dp[1].F << ' ' << dp1[v] << '\n';
 	for (int i = 0; i < n - 1; i ++){
		cin >> v >> u;
		g[v].pb(u), g[u].pb(v);
	}
	DFS(1), DFS1(1);
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		//cout << i << ' ' << dp[i].F << ' ' << dp1[i] << '\n';
		if (max(dp[i].F, dp1[i]) <= q) ans ++;
	}
	cout << ans;
	
	
	
	
	
	return 0;
}
 
 