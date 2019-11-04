#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int m,n,ma,md;
    scanf("%d %d",&m,&n);
    ma=md=0;
    int sa[102],sd[102],s[102],ln[102];
    for(int i=0;i<m;i++){
        char attr[5];
        int tmp;
        scanf("\n%s %d",attr,&tmp);
        if(!strcmp(attr,"ATK")){
            sa[ma++]=tmp;
        }else sd[md++]=tmp;
    }
    sort(sa,sa+ma);
    sort(sd,sd+md);
    for(int i=0;i<n;i++) scanf("%d",&ln[i]);
    sort(ln,ln+n);
    int ans=0;
    for(int k=min(n,ma)-1;k>=0;k--){
        int cnt=0,j=n-1;
        for(int i=k;i>=0 && j>=0;i--){
            if(ln[j]>=sa[i]){
                cnt+=ln[j]-sa[i];
                --j;
            }
        }
        ans=max(ans,cnt);
    }
    if(m<n){
        bool use[102];
        int cnt2=0;
        memset(use,0,sizeof(use));
        for(int i=md-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(!use[j] && ln[j]>sd[i]){
                    use[j]=true;
                    goto gg1;
                }
            }
            goto end;
            gg1:;
        }
        for(int i=0;i<n;i++) if(!use[i]) cnt2+=ln[i];
        for(int i=0;i<ma;i++) cnt2-=sa[i];
        for(int i=ma-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(!use[j] && ln[j]>=sa[i]){
                    use[j]=true;
                    goto gg2;
                }
            }
            goto end;
            gg2:;
        }
        ans=max(ans,cnt2);
    }
    end:;
    printf("%d\n",ans);
    return 0;
}