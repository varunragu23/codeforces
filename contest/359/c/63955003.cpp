#include <cstdio>
#include <cstdlib>
#include <iostream>
#define mod 1000000007
using namespace std;
 
int n,i,j,k;
long long a[2333333],b[2333333],ans,p,tmp,x,sum;
 
void init()
{
    scanf("%d%I64d",&n,&x);
    for(i=1;i<=n;++i)scanf("%I64d",&a[i]),b[i]=1,sum+=a[i];
}
 
void outit(long long p)
{
    if(p>sum)p=sum;
    tmp=x;ans=1;
    while(p)
    {
        if(p&1)ans=ans*tmp%mod;
        tmp=tmp*tmp%mod;
        p>>=1;
    }
    cout << ans;
    exit(0);
}
 
void work()
{
    for(i=1;i<=n;++i)a[i]=sum-a[i];
    for(i=n-1;i>=1;--i)
    {
        if(a[i]==a[i+1])b[i]+=b[i+1];
        else
        {
            while(a[i]!=a[i+1]){if(b[i+1]%x)outit(a[i+1]);b[i+1]/=x;++a[i+1];}
            b[i]+=b[i+1];
        }
    }
    while(b[1]%x==0)b[1]/=x,++a[1];
}
 
int main()
{
    init();
    work();
    outit(a[1]);
}