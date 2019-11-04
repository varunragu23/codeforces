#include <cstdio>
#include <algorithm>
#include <ctime>
 
#define forn(i, n) for(int i = 0; i < int(n); i++)
 
const int MOD = 1000000007;
const int N = 5005;
 
int d[2][N], n, a, b, k;
 
bool read() {
	if (scanf("%d %d %d %d", &n, &a, &b, &k) != 4) 
		return false;
    
    a--, b--;
 
    return true;
}
 
int add(int a, int b) {
 	int res = a + b;
 
 	while (res >= MOD) res -= MOD;
 
 	while (res < 0) res += MOD;
 
 	return res;
}
 
int abs(int a) {
 	if (a < 0) return -a;
 
 	return a;
}
 
void solve() {
 
	d[0][a] = 1;	
 
	forn(it, k) {               	
 
		int i = it & 1;
		int nxt = i ^ 1;
 
		forn(j, n)
		 	d[nxt][j] = 0;
 
		forn(j, n) {
			int dv = d[i][j];
 
			int diff = abs(j - b);
 
			d[nxt][std::max(j - diff + 1, 0)] = add(d[nxt][std::max(j - diff + 1, 0)], dv);
			d[nxt][std::min(j + diff, N - 1)] = add(d[nxt][std::min(j + diff, N - 1)], -dv);	
		}	
 
		forn(j, n)
		 	if (j > 0) 
		 		d[nxt][j] = add(d[nxt][j], d[nxt][j - 1]);
 
		forn(j, n)
		 	d[nxt][j] = add(d[nxt][j], -d[i][j]);
	}	
 
	int ans = 0;
 
	forn(j, n) 
		ans = add(ans, d[k & 1][j]);
 
	printf("%d\n", ans);
	fprintf(stderr, "%d\n", ans);
	fprintf(stderr, "%d\n", clock());
}
 
int main() {
 
	if (!read()) throw;
 
	solve();	
}