#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
 
const int MAX_N = 5000 + 10;
char map[MAX_N][MAX_N];
int rt[MAX_N][MAX_N];
int n, m;
 
int main() {
	scanf("%d%d", &n, &m);
	for (int r = 0; r < n; ++r) {
		scanf("%s", map[r]);
	}
 
	for (int r = 0; r < n; ++r) {
		rt[r][m] = 0;
		for (int c = m - 1; c >= 0; --c) {
			rt[r][c] = map[r][c] == '1' ? rt[r][c + 1] + 1 : 0;
		}
	}
 
	int ans = 0;
 
	for (int c = 0; c < m; ++c) {
		static int a[MAX_N];
		for (int r = 0; r < n; ++r) {
			a[r] = rt[r][c];
		}
		sort(a, a + n);
 
		for (int r = 0; r < n; ++r) {
			ans = max(ans, a[r] * (n - r));
		}
	}
 
	cout << ans << endl;
	return 0;
}