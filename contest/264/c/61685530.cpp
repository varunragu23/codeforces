#include <bits/stdc++.h>
 
#define F first
#define S second
#define all(c) c.begin(), c.end()
#define endl '\n'
#define pb push_back
 
typedef long long ll;
typedef long double ld;
 
using namespace std;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
 
const ld PI = 3.141592653589793;
const ll INF = 922337203685477587ll;
const ll mod = 1e9 + 7;
 
void solve() 
{
	int n, q;
	cin >> n >> q;
	vector<ll> v(n);
	vector<ll> c(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	for (int i = 0; i < n; ++i) cin >> c[i];
	while (q--) {
		ll a, b;
		cin >> a >> b;
		vector<ll> dp(n + 1, -INF);
		dp[0] = 0;
		int c1 = 0, c2 = 0;
		for (int i = 0; i < n; ++i) {
			dp[c[i]] = max(dp[c[i]], dp[c[i]] + v[i] * a);
			if (c1 != c[i]) {
				dp[c[i]] = max(dp[c[i]], dp[c1] + v[i] * b);
			} else dp[c[i]] = max(dp[c[i]], dp[c2] + v[i] * b);
			if (dp[c[i]] > dp[c1]) {
				c2 = c1;
				c1 = c[i];
			} else if (dp[c[i]] > dp[c2] && c1 != c[i]) {
				c2 = c[i];
			}
		}
		cout << dp[c1] << endl;
		for (int i = 0; i <= n; ++i) dp[i] = -INF;
	}
}
 
int main( )
{   
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    solve();
    return 0;
}