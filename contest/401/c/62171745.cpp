#include <cmath>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <bitset>
#include <memory.h>
#include <functional>
#include <queue>
#include <fstream>
#include <ctime>
#include <deque>
#include <utility>
#include <stack>
#include <sstream>
#include <list>
#include <cctype> 
#include <numeric> 
#include <iomanip>
#include <assert.h>
using namespace std;
#define sqr(_) ((_)*(_))
 
typedef pair<int, int> Pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
 
typedef long long LL;
 
const int MAXN = 1000000 + 10;
 
int n, m;
 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m;
	if (m < n - 1 || n < (m + 1) / 2 - 1)
		puts("-1"), exit(0);
	for (int p = !(m == n - 1); n || m; p ^= 1)
	{
		if (!p) printf("0"), --n;
		else
		if (m - 1 <= n)
			printf("1"), --m;
		else
		printf("11"), m -= 2;
	}
	puts("");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}