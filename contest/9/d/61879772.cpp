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
 
#define Pi 3.14159265
#define hash1 1000003
#define hash2 1000033
#define md 1000000007
#define INF 1000000000
#define mp make_pair
#define pb push_back
#define S size()
#define max(aa,bb) (aa>bb?aa:bb)
#define min(aa,bb) (aa<bb?aa:bb)
#define fi first
#define se second
#define PI pair < int,int >
 
using namespace std;
 
long long N,H,p,n,h,i,j,k,h2,ans;
long long dp[100][100];
 
main()
{
 //   freopen("text.in","r",stdin);freopen("text.out","w",stdout);
    cin>>N>>H;
 
    dp[1][1]=1;
    dp[0][0]=1;
 
    n=N;
 
    for (i=2;i<=n;i++)
    for (j=1;j<=n;j++)
    for (k=0;k<i;k++)
    {
          p=i-1-k;
          for (h2=0;h2<j-1;h2++)
          dp[i][j]+=dp[k][j-1]*dp[p][h2];
 
          for (h2=0;h2<=j-1;h2++)
          dp[i][j]+=dp[k][h2]*dp[p][j-1];
    }
 
   /* for (i=0;i<=n;i++){
    for (j=1;j<=n;j++)
    cout<<dp[i][j]<<" ";
    cout<<endl;
    }*/
 
    for (i=H;i<=N;i++)
    ans+=dp[N][i];
    cout<<ans<<endl;
}