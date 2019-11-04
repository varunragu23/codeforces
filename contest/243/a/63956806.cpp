#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>
#include <bitset>
#include <string>
#include <vector>
#include <sstream>
#define zero(a) (abs(a)<eps)
#define lowbit(a) ((a)&(-(a)))
#define abs(a) ((a)>0?(a):(-(a)))
#define dj(x1,y1,x2,y2) ((x1)*(x2)+(y1)*(y2))
#define cj(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y1))
#define dis(x1,y1,x2,y2) (((x2)-(x1))*((x2)-(x1))+((y2)-(y1))*((y2)-(y1)))
const double eps = 1e-9;
const double pi = acos(-1);
const int oo = 1000000000;
const int mod = 1000000009;
const double E = 2.7182818284590452353602874713527;
using namespace std;
 
int a[100001],s[2222222],rec[100001][21];
 
int main()
{
   int n,ans=0;
   cin>>n;
   for (int i=1;i<=n;i++)
   {
      scanf("%d",&a[i]);
      for (int j=0;j<=20;j++)
         if (a[i]&(1<<j))
            rec[i][j]=i;
         else
            rec[i][j]=rec[i-1][j];
   }
   for (int i=n;i>=1;i--)
   {
      int t=a[i],x=i;
      s[t]=1;
      while (1)
      {
         int p=0;
         for (int j=0;j<=20;j++)
            if (!(t&(1<<j))&&rec[x][j]>p)
               p=rec[x][j];
         if (!p)
            break;
         t|=a[p];
         s[t]=1;
         x=p;
      }
   }
   for (int i=0;i<(1<<21);i++)
      ans+=s[i];
   cout<<ans<<endl;
   return 0;
}