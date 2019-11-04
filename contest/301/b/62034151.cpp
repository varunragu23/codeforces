#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
using namespace std;
#define PI                      3.1415926535897932384626
#define int                     long long int
#define fi                      first
#define se                      second
#define pq                      priority_queue
#define pb                      push_back
#define endl                    '\n'
#define all(x)                  x.begin(),x.end()
#define pii                     pair<int,int>
#define fill(x,y)               memset(x,y,sizeof(x));
#define fast                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define hash                    _H
#define lg                      long double         
#define vi                      std::vector<int>
#define sz(x)                   ((int)x.size())
 
 
 
template<typename T> T pow(T a,T b, int m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }
template<typename T>T InverseMod(T a,int m){return pow(a,m-2,m);}
template<typename T>int SquareDist(T a,T b){int x = abs(a.fi - b.fi),y = abs(a.se - b.se); return x*x + y*y;}
 
 
 
 
 
 
 
void solve() {
    
    int n,di;
    cin >> n >> di;
    int arr[n];
    arr[0] = 0;
    arr[n-1] = 0;
    int d[n][n];
    for(int i =1; i <= n-2; ++i) {
        cin >> arr[i];
    }
    std::vector<pii> v;
    for(int i  =0; i < n; ++i) {
        int a,b;
        cin >> a >> b;
        v.pb({a,b});
    }
    for(int i  = 0 ; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            d[i][j] = di*(abs(v[i].fi - v[j].fi) + abs(v[i].se - v[j].se)) - arr[i];
        }
    }
    for(int k = 0; k < n; ++k) {
        for(int i = 0 ; i < n; ++i) {
            for(int j = 0; j < n; ++j ) {
                if(i != j and j != k and i != k)
                    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);     
            }
        }
    }
    cout << d[0][n-1] << endl;
}
 
 
 
 
signed main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
} 