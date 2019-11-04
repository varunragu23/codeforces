#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int maxn=100100;
int n,m;
vector<int> a[maxn],b[maxn];
int dis[maxn];
queue<int>q;
int vis[maxn];
map<int , bool > ma[maxn];
void init()
{
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[x].push_back(y);
        b[x].push_back(z);
        a[y].push_back(x);
        b[y].push_back(z);
    }
    for (int i=1; i<=n; i++)
    {
        int x;
        scanf("%d",&x);
        for (int j=1; j<=x; j++)
        {
            int y;
            scanf("%d",&y);
            //c[i].push_back(y);
            ma[i][y]=true;
        }
    }
}
void spfa()
{
    vis[1]=true; q.push(1);
    memset(dis,0x3f3f3f3f,sizeof(dis));
    dis[1]=0;
    while (!q.empty())
    {
        int x=q.front();
        int y=dis[x];
        while (ma[x].find(y)!=ma[x].end()) y++;
        for (int i=0; i<a[x].size(); i++)
        {
            int z=a[x][i],cc=b[x][i];
            if (y+cc<dis[z])
            {
                dis[z]=y+cc;
                if (!vis[z])
                {
                    vis[z]=true;
                    q.push(z);
                }
            }
        }
        q.pop();
        vis[x]=false;
    }
}
int main()
{
    //freopen("input.cpp","r",stdin);
    init();
    spfa();
    if(dis[n]<(1e9+100000))
    cout<<dis[n]<<endl;else
    cout<<-1<<endl;
}