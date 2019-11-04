#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <functional>
#include <bitset>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long
 
int a,b,c,d,n,m,k;
bool row[1002], col[1002];
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
 
	scanf("%d%d", &n, &m);
	rept(i, m) {
		scanf("%d%d", &a, &b); --a; --b;
		row[a] = 1;
		col[b] = 1;
	}
 
	int ans = 0;
	rept(i, n) {
		if (!i) continue;
		if (n - i - 1 < i) break;
		int cur = 0;
		FOR(r1, -1, 1) {
			if (r1 && row[i]) continue;
			FOR(r2, -1, 1) {
				if (r2 && row[n - i - 1]) continue;
				if (i == n - i - 1 && r1 != r2) continue;
				FOR(c1, -1, 1) {
					if (c1 && col[i]) continue;
					FOR(c2, -1, 1) {
						if (c2 && col[n - i - 1]) continue;
						if (i == n - i - 1 && c1 != c2) continue;
						if (r1 && c1 && r1 == c1) continue;
						if (r2 && c2 && r2 == c2) continue;
						if (r1 && c2 && r1 != c2) continue;
						if (r2 && c1 && r2 != c1) continue;
						cur = max(cur, abs(r1) + abs(r2) + abs(c1) + abs(c2));
					}
				}
			}
		}
		if (i == n - i - 1) cur /= 2;
		ans += cur;
	}
	printf("%d\n", ans);
}