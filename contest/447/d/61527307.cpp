#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
 
char ch;
 
void read(int &x)
{
    x=0;
    ch=getchar();
    while (ch<=32) ch=getchar();
    while (ch>32) x=x*10+ch-48,ch=getchar();
}
 
int n,m,k,p;
int a[1005][1005];
int s1[1005];
int s2[1005];
 
long long ans1[1000005];
long long ans2[1000005];
 
std::priority_queue<long long> pq;
 
void solve1()
{
    while (!pq.empty()) pq.pop();
    int i;
    for (i=1;i<=n;i++) {
        pq.push(s1[i]);
    }
    ans1[0]=0;
    long long now=0;
    for (i=1;i<=k;i++) {
        long long tmp=pq.top();
        now+=tmp;
        pq.pop();
        pq.push(tmp-1LL*p*m);
        ans1[i]=now;
    }
}
 
void solve2()
{
    while (!pq.empty()) pq.pop();
    int i;
    for (i=1;i<=m;i++) {
        pq.push(s2[i]);
    }
    ans2[0]=0;
    long long now=0;
    for (i=1;i<=k;i++) {
        long long tmp=pq.top();
        now+=tmp;
        pq.pop();
        pq.push(tmp-1LL*p*n);
        ans2[i]=now;
    }
}
 
long long ans;
 
void solve()
{
    solve1();
    solve2();
    ans=-1000000000000000000LL;
    int i;
    for (i=0;i<=k;i++) {
        long long tmp=ans1[i]+ans2[k-i]-1LL*i*(k-i)*p;
        if (tmp>ans) ans=tmp;
    }
}
 
int main()
{
    read(n);read(m);read(k);read(p);
    int i,j;
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++) {
            read(a[i][j]);
            s1[i]+=a[i][j];
            s2[j]+=a[i][j];
        }
    }
    solve();
    printf("%I64d\n",ans);
}