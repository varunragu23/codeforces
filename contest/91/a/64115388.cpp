#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <string>
 
using namespace std;
 
char s[20000],t[2000000];
int nx[20000][30];
int a[20000];
 
int main()
{
	scanf("%s%s",&s,&t);
	int n=strlen(s);
	int m=strlen(t);
	int i,j,k,l,ans=1;
	for(i=0;i<26;i++)
	{
		k=0;
		memset(a,-1,sizeof(a));
		for(j=0;j<n;j++)
			if(s[j]==i+'a')
				a[k++]=j;
		if(k==0)
		{
			for(l=0;l<=n;l++)
				nx[l][i]=-1;
			continue;
		}
		nx[n][i]=a[0];
		for(l=0;l<a[0];l++)
			nx[l][i]=a[0];
		for(j=0;j<k-1;j++)
			for(l=a[j];l<a[j+1];l++)
				nx[l][i]=a[j+1];
		for(l=a[k-1];l<n;l++)
			nx[l][i]=-1;
	}
	j=n;
	for(i=0;i<m;i++)
	{
		j=nx[j][t[i]-'a'];
		if(j==-1)
		{
			if(nx[n][t[i]-'a']==-1)
				break;
			j=nx[n][t[i]-'a'];
			ans++;
		}
	}
	if(i==m)
		printf("%d\n",ans);
	else
		printf("-1\n");
	return 0;
}