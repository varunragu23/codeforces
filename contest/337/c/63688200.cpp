#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define int64 long long
#define mo 1000000009
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j;
int64 n,m,k;
int64 a[2],b[2][2];
inline void mul(int64 a[2],int64 b[2][2]) {
    int64 c[2]={0}; int i,j;
    For(i,0,1)For(j,0,1) c[j]+=a[i]*b[i][j];
    For(i,0,1) a[i]=c[i]%mo;
}
inline void multi(int64 a[2][2],int64 b[2][2]) {
    int64 c[2][2]={0}; int i,j,u;
    For(i,0,1)For(j,0,1)For(u,0,1) c[i][u]+=a[i][j]*b[j][u];
    For(i,0,1)For(j,0,1) a[i][j]=c[i][j]%mo;
}
inline int64 work(int64 x) {
    a[1]=1; b[0][0]=2; b[1][0]=2*k; b[1][1]=1;
    for (;x;x>>=1) {
        if (x&1) mul(a,b);
        multi(b,b);
    } return a[0];
}
inline int64 calc() {
    int64 B=n/k*(k-1)+n%k;
    if (B>=m) return m;
    m-=B;
    B=B-m*(k-1);
    return work(m)+B;
}
int main() {
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    printf("%I64d\n",calc()%mo);
    return 0;
}