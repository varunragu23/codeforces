#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000010];
int n,i,m,a[1000010];
 
void dfs(int x)
{
	if(x>n) return;
	if(s[x]=='r') a[++m]=x;
	dfs(x+1);
	if(s[x]=='l') a[++m]=x;
}
 
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	dfs(1);
	for(i=1;i<=m;i++) printf("%d\n",a[i]);
}