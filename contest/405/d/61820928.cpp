#include <cstdio>
#include <vector>
using namespace std;
 
const int MAX_N=1000000;
 
bool viz[MAX_N+100];
 
vector<int>v;
 
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int a;
        scanf("%d",&a);
        viz[a]=true;
    }
    
    n=MAX_N;
    int cat=0;
    for(int i=1;i<=n/2;i++) {
        if(viz[i]) {
            if(!viz[n-i+1]) {
                v.push_back(n-i+1);
                viz[n-i+1]=true;
            }
            else {
                cat++;
            }
        }
        else if(viz[n-i+1]) {
            v.push_back(i);
            viz[i]=true;
        }
    }
    
    for(int i=1;i<=n/2&&cat;i++) {
        if(cat&&!viz[i]) {
            cat--;
            v.push_back(i);
            v.push_back(n-i+1);
        }
    }
    
    printf("%d\n",(int)v.size());
    for(auto it=v.begin(); it!=v.end(); it++) {
        printf("%d ",*it);
    }
    return 0;
}