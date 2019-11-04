#include <bits/stdc++.h>
 
using namespace std;
 
const long long Inf = 1e15;
const int N = 200001;
vector <int> g[N];
long long a[N], sum = 0, fin[N], m[N];
 
void End() {
	printf("%I64d", sum);
	exit(0);
}
 
void dfs(int v, int par, long long now) {
	if (now > sum) 
		End();
	fin[v] = now;
	long long deg = g[v].size() - (par == v ? 0 : 1);
	for (auto u : g[v])
		if (u != par) {
			if (sum / deg < now) 
				End();
			dfs(u, v, now * deg);
		}
}
 
main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i), sum += a[i];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[--u].push_back(--v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
		if (g[i].size() != 1 || i == 0)
			sum -= a[i], a[i] = 0;
	dfs(0, 0, 1);
	long long temp = 1;
	for (int i = 1; i < n; i++) 
		if (g[i].size() == 1) {
			long long d = __gcd(temp, fin[i]);
			temp = temp * fin[i] / d;
			if (temp > sum) 
				End();
		}
	long long maxi = sum;
	for (int i = 1; i < n; i++)
		if (g[i].size() == 1)
			maxi = min(maxi, fin[i] * a[i]);
	long long ans = sum - maxi / temp * temp;
	printf("%I64d", ans);
}