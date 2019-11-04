#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <memory.h>
 
using namespace std;
 
#define FOR(i, a, b) for(int i=(a), _b(b); i<_b; ++i)
#define FORD(i, b, a) for(int i=(b)-1, _a(a); i>=_a; --i)
#define SZ(a) (int)(a).size()
#define FILL(a, b) memset(a, b, sizeof(a))
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
 
template<typename T>
void Out(T res)
{
	cout << res << endl;
	exit(0);
}
 
int n, m;
string s[1024];
char ch[1024];
PII a[26];
 
int di[] = {-1, +1, 0, 0};
int dj[] = {0, 0, -1, +1};
 
int DistUp[1024][1024];
int DistLeft[1024][1024];
 
int main()
{
#ifdef ALMAG_LOCAL
	freopen("input.txt", "r", stdin);
#else
	//freopen("shooting.in", "r", stdin);
	//freopen("shooting.out", "w", stdout);
#endif
 
	FOR(i, 0, 26) a[i] = PII(-1, -1);
 
	scanf("%d %d", &n, &m);
	FOR(i, 0, n)
	{
		scanf("%s", ch);
		s[i] = string(ch);
		FOR(j, 0, SZ(s[i]))
			if (isalpha(s[i][j]))
				a[s[i][j]-'A'] = PII(i, j);
	}
 
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			if (s[i][j]=='#')
			{
				DistUp[i][j] = -1;
				DistLeft[i][j] = -1;
			}
			else
			{
				if (i) DistUp[i][j] = DistUp[i-1][j]+1;
				if (j) DistLeft[i][j] = DistLeft[i][j-1]+1;
			}
		}
	}
 
	int k; scanf("%d", &k);
	FOR(i, 0, k)
	{
		int len, p;
		scanf("%s %d", ch, &len);
		switch (ch[0])
		{
			case 'N' : p=0; break;
			case 'S' : p=1; break;
			case 'W' : p=2; break;
			case 'E' : p=3; break;
		}
 
		FOR(j, 0, 26)
			if (a[j] != PII(-1, -1))
			{
				bool fl;
				if (p==0)
					fl = (DistUp[a[j].first][a[j].second]>=len);
				if (p==1)
					fl = (DistUp[a[j].first+len][a[j].second]>=len);
				if (p==2)
					fl = (DistLeft[a[j].first][a[j].second]>=len);
				if (p==3)
					fl = (DistLeft[a[j].first][a[j].second+len]>=len);
				if (fl)
					a[j] = make_pair(a[j].first+di[p]*len, a[j].second+dj[p]*len);
				else
					a[j] = PII(-1, -1);
			}
	}
 
	int res = 0;
	FOR(j, 0, 26)
		if (a[j] != PII(-1, -1))
			printf("%c", j+'A'), res++;
	if (!res)
		printf("no solution");
	printf("\n");
 
	return 0;
}