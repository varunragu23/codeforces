#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS
 
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>
 
using namespace std;
 
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
 
typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;
 
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
 
template <class T> T sqr (T x) {return x * x;}
 
map <int, int> S;
int a[100000]; 
 
int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int n;
	int64 k;
	cin >> n >> k;
	S.clear ();
	forn (i, n)
		scanf ("%d", &a[i]);
	forn (i, n) 
		if (S.count (a[i]))
			S[a[i]] ++;
		else
			S[a[i]] = 1;
	int64 sum = 0;
	forn (i, n)
		sum += a[i];
	if (sum < k) {
		cout << -1 << endl;
		return 0;
	}
	int64 N = n;
	int64 cur = 0;
	for (map <int, int> :: iterator it = S.begin(); it != S.end(); it ++)
		if (N * (it->fs - cur) <= k) {
			k -= N * (it->fs - cur);
			cur = it->fs;
			N -= it->sc;
		} else {
			cur += k / N;
			k %= N;
			break;
		}
	int l = 0;
	forn (i, n) 
		if (a[i] > cur) {
			if (k == 0) {
				l = i;
				break;
			} else
				k --;
		}
	for (int i = l; i < n; i ++)
		if (a[i] > cur)
			printf ("%d ", i+1);
	for (int i = 0; i < l; i ++)
		if (a[i] > cur+1)
			printf ("%d ", i+1);
	printf ("\n");
	return 0;
}