#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    int n,ans=0;
    cin>>n;
    pair<int,int> a[n];
    for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
    sort(a,a+n);
    for(int i=0;i<n;i++)
        if(ans>a[i].second)ans=a[i].first;
        else ans=max(ans,a[i].second);
    cout<<ans<<endl;
    return 0;
}