#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <climits>
using namespace std;
 
#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define RREP(i,n) for(int i=(int)n-1; i>=0; i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pipii;
typedef vector<int> vi;
 
const int INF = 1e9;
const int MOD = 1e9+7;
 
int main(void){
    int n;
    cin >> n;
    vi a(n);
    REP(i, n){
        cin >> a[i];
        a[i]--;
    }
    if(a[n-1] == 1){
        REP(i, n) a[i] = !a[i];
    }
    vi wa(n + 1, 0), wb(n + 1, 0);
    for(int i = 0; i < n; i++){
        wa[i + 1] = wa[i] + (a[i]? 0:1);
        wb[i + 1] = wb[i] + (a[i]? 1:0);
    }
    vector<pair<int, int> > ans;
    for(int t = 1; t <= n; t++){
        //cout << " t: " << t << endl;
        int s = 0, s2 = 0;
        int es = 0;
        bool finish = false;
        while(1){
            if(es == n){
                finish = true;
                break;
            }
            int l = es - 1, r = n;
            while(r - l > 1){
                //cout << "loop" << l << ":" << r << endl;
                int med = (r + l) / 2;
                int x = wa[med] - wa[es];
                int y = wb[med] - wb[es];
                if(max(x, y) >= t) r = med;
                else l = med;    
            }
            int med = (l + r) / 2;
            //cout << wa[med] - wa[es] << " " << wb[med] - wb[es] << endl;
            if(wa[med] - wa[es] != t && wb[med] - wb[es] != t) med++;
            if(wa[med] - wa[es] != t && wb[med] - wb[es] != t) break;
            if(wa[med] - wa[es] == wb[med] - wb[es]) break;
            //cout << "med : " << med << endl;
            if(!a[med - 1]) s++;
            else s2++;
            es = med;
        }
        if(finish && s > s2) ans.push_back(make_pair(s, t));
    }
    sort(ALL(ans));
    cout << ans.size() << endl;
    FOR(e, ans){
        cout << (*e).first << " " << (*e).second << endl;
    }
    return 0;
}