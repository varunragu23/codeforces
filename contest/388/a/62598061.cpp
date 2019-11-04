#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <time.h>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <stack>
#include <queue>
#include <bitset>
#include <vector>
#include <iomanip>
#include <iostream>
#include <assert.h>
 
#define ALL(x) x.begin(), x.end()
#define fill(a, b) memset(a, b, sizeof(a))
#define abs(x) ((x)>0?(x):-(x))
#define sqr(x) (1ll*(x)*(x))
#define min(a,b) ((a)>(b)?(b):(a))
#define max(a,b) ((a)<(b)?(b):(a))
#define gcd(a,b) __gcd(a,b)
#define F first
#define S second
#define SS stringstream
#define CC(x) cout << x << endl
#define CCS(x) cout << x << " "
#define pw(x) (1ll<<(x))
#define pb push_back
#define mp make_pair
#define FIN freopen("1.in", "r", stdin)
#define FOUT freopen("1.out", "w", stdout)
#define FILE FIN; FOUT
#define SC(x) scanf("%d", &x)
#define PR(x) printf("%d\n", x)
#define PRS(x) printf("%d ", x)
#define bits(mask) __builtin_popcount(mask)
#define bit(mask, i) ((mask & pw(i-1)) > 0)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int> > 
#define forr(i, l, r) for (int i = l; i <= r; i++)
#define ford(i, r, l) for (int i = r; i >= l; i--)
#define SRD srand((int)time(NULL))
#define GC getchar()
#define PC(x) putchar(x)
#define left lft
#define right rght
#define log lg
#define y1 yyy1
 
typedef long long LL;
typedef unsigned long long ULL;
typedef double DD;
typedef long double LD;
typedef unsigned char UC;
typedef unsigned int UI;
typedef unsigned short US;
 
using namespace std;
 
#define N 111
 
int n, a[N], b[N], k;
 
int main(int argc, char * argv[])
{
	//ios_base::sync_with_stdio(0);
	SC(n);
	forr(i, 1, n) SC(a[i]);
	sort(a+1, a+n+1);
	k = 1; b[1] = 1;
	forr(i, 2, n)
	{
		int p = -1;
		forr(j, 1, k)
			if (b[j] <= a[i])
			{
				p = j;
				break;
			}
		if (p != -1) b[p]++; else k++, b[k] = 1;
	}
	CC(k);
	return 0;
}