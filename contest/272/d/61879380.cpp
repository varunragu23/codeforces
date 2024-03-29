#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
 
using namespace std;
 
#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned
 
LL fact[200200];
vector<pnt > a;
 
int main()
{
#ifdef Fcdkbear
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	double beg=clock();
#endif
 
	int n;
	scanf("%d",&n);
	a.resize(n+n);
	FOR(i,0,n+n)
	{
		scanf("%d",&a[i].first);
		a[i].second=i%n;
	}
	int m;
	scanf("%d",&m);
	fact[0]=1;
	FOR(i,1,200100)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=m;
	}
	LL res=1;
	sort(a.begin(),a.end());
	int cnt1=0,cnt2=0;
	FOR(i,0,a.size()+1)
	{
		if ((i==a.size()) || ((i) && (a[i].first!=a[i-1].first)))
		{
			FOR(j,1,cnt1+1)
			{
				int v=j;
				if ((cnt2) && ((j&1)==0))
				{
					cnt2--;
					v/=2;
				}
				res*=v;
				res%=m;
			}
			cnt1=0;
			cnt2=0;
		}
		if (i==a.size())
			break;
		cnt1++;
		if ((i) && (a[i]==a[i-1]))
			cnt2++;
	}
	cout<<res<<endl;
return 0;
}