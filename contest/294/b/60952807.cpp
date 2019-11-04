#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
 
 
using namespace std;
 
#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif
 
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ll> vll;
typedef vector<vll> vvll;
 
ll rdtsc() {
    ll tmp;
    asm("rdtsc" : "=A"(tmp));
    return tmp;
}
 
#define TASKNAME "text"
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define INF ((int)1e9)
#define sqr(x) ((x) * (x))         
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
 
const int maxn = 100;
pii a[maxn];
 
int main() {
	srand(rdtsc());
#ifdef DEBUG
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
#endif
	
	int n;
	while (scanf("%d", &n) >= 1) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a[i].first, &a[i].second);
		}
		sort(a, a + n);
		reverse(a, a + n);
		int sumw = 0;
		for (int i = 0; i < n; i++) {
			sumw += a[i].second;
		}
		int m = 0;
		for (; m < n && a[m].first != 1; m++) ;
		
		int ans = INF;
		for (int i = 0, sum0 = 0; i <= m; i++) {
			for (int j = m, sum = sum0; j <= n; j++) {
				if (sumw - sum <= i * 2 + j - m) {
// 					eprintf("%d %d\n", i, j);
					ans = min(ans, i * 2 + j - m);
				}
				if (j < n)
					sum += a[j].second;
			}
			if (i < m)
				sum0 += a[i].second;
		}
		
		printf("%d\n", ans);
		//break;
	}
	return 0;
}