#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
 
int main() {
	int n,i,j=0; vector<int> v,vv;
	scanf("%d",&n);
	v.resize(n);
	for(i=0;i<n;i++)scanf("%d",&v[i]);
	vv=v;
	sort(vv.begin(),vv.end());
	for(i=0;i<n;i++)if(vv[i]!=v[i]&&++j>2){puts("NO");return 0;}
	puts("YES");
	return 0;
}