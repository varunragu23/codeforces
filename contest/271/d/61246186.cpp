#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cassert>
#include <ctime>
#include <set>
#include <map>
 
using namespace std;
 
#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif
 
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ll> vll;
typedef vector<vll> vvll;
 
#define TASKNAME "text"
#define pb push_back
#define mp make_pair
#define EPS (1E-9)
#define INF ((int)1E9)
#define sqr(x) ((x) * (x))
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
        
int main() {     
	#ifdef DEBUG
		freopen(TASKNAME".in", "r", stdin);
		freopen(TASKNAME".out", "w", stdout);
	#endif
	
	string s, good;
	int k;
	while (cin >> s >> good >> k) {
		for (int i = 0; i < 26; i++)
			good[i] -= '0';
		
		int n = sz(s);
		vector<string> sts(n);
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			int len = 0;
			while (i + len < n) {
				cnt += !good[s[i + len] - 'a'];
				if (cnt > k)
					break;
				len++;
			}
			sts[i] = string(s, i, len);
		}
		
		sort(sts.begin(), sts.end());
		int res = 0;
		for (int i = 0, bal = 0; i < n; i++) {
			res += sz(sts[i]) - bal;
			if (i < n - 1) {
				bal = 0;
				while (bal < sz(sts[i]) && bal < sz(sts[i + 1]) && sts[i][bal] == sts[i + 1][bal])
					bal++;
			}
		}
		printf("%d\n", res);
	}	
	return 0;
}