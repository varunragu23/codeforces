#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <set>
 
#define EPS 0.000000001
#define Pi 3.1415926535897932384626433832795028841971
#define hash1 1000003
#define hash2 1000033
#define md 1000000007
#define INF 1000000500
#define mp make_pair
#define pb push_back
#define S size()
#define MX(aa,bb) (aa>bb?aa:bb)
#define MN(aa,bb) (aa<bb?aa:bb)
#define fi first
#define se second
#define PI pair < long long,long long >
#define REP(i,a,n) for(i=a;i<n;i++)
#define sc scanf
#define pt prlong longf
#define big long long
#define VI vector <long long>
#define DID (long long)
 
 
using namespace std;
 
const long long T=1000005;
 
long long t,was,need,sul,b,d,I,J,i;
long long ans[T],fix[T],raod[T],start[T];
string a,c;
 
void solve()
{
    t=i-start[I];
    was=raod[I];
 
    need=( DID (DID a.S*b-i)/t + 1)*(ans[i-1]-ans[start[I]-1]) + was ;
 
    long long left=(DID a.S*b-i)%t;
 
    need+=ans[start[I]+left-1]-ans[start[I]-1];
    cout<<need/d<<endl;
 
    exit(0);
}
 
main()
{
   // freopen("text.in","r",stdin);   freopen("text.out","w",stdout);
 
    cin>>b>>d;
    cin>>a;
    cin>>c;
 
    for (i=0;i<DID a.S*b;i++)
    {
        I=i%a.S;
 
        if (J==0)
        if (fix[I]) solve();
 
        if (J==0){
        fix[I]=1;
        start[I]=i;
        raod[I]=sul;
        }
 
        if (a[I]==c[J])
        {
            J=(J+1)%c.S;
            if (J==0) sul++;
        }
 
        ans[i]=sul;
    }
 
    sul/=d;
    cout<<sul<<endl;
 
}