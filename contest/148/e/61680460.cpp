#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
 
using namespace std;
 
int f[10002],v[102],a[102][102],n,m,w[102],F[102][102],A[102];
 
int main(){
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    scanf("%d%d",&n,&m);
    memset(a,128,sizeof(a));
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        for (int j=1;j<=w[i];j++) scanf("%d",&A[j]);
        memset(F,128,sizeof(F));
        F[1][w[i]]=0;
        for (int j=1;j<=w[i];j++)
           for (int k=w[i];k>=j;--k)
           {
               if (F[j][k]+A[k]>=F[j][k-1]) F[j][k-1]=F[j][k]+A[k];
               if (F[j][k]+A[j]>=F[j+1][k]) F[j+1][k]=F[j][k]+A[j];
           }
        for (int j=0;j<=w[i]+1;j++)
           for (int k=0;k<=w[i]+1;k++)
              if (w[i]-k+j-1<=w[i] && F[j][k]>a[i][w[i]-k+j-1]) a[i][w[i]-k+j-1]=F[j][k]; 
    }
    memset(f,128,sizeof(f));
    f[0]=0;
    for (int i=1;i<=n;i++)
       for (int j=m;j>=0;--j)
        if (f[j]>-1<<30)
         for (int k=1;k<=w[i];k++)
            if (j+k<=m && a[i][k]>=-1<<30 && f[j]+a[i][k]>f[j+k]) f[j+k]=f[j]+a[i][k];
    printf("%d\n",f[m]);
}
