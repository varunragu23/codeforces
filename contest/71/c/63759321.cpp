#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#define REP(i,x) for(int i = 0 ; i < (int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long
using namespace std;
template<class T> inline int __builtin_popcount(T n){return (n==0)?0:(1+__builtin_popcount(n&(n-1)));}
 
int table[100000];
 
int main(){
    int N;
    while(cin >> N){
        REP(i,N)cin >> table[i];
        vector<int> div;
        for(int i = 1 ; i*i <= N ; i++){
            if(N%i==0){
                int a = N/i;
                if(a>=3)div.push_back(i);
                if(i!=a && i>=3)div.push_back(a);
            }
        }
        bool can = false;
        REP(i,div.size()){
            int d = div[i];
            for(int s = 0 ; s < d ; s++){
                int k = 1;
                for(int j = s ; j < N ; j+=div[i]){
                    k &= table[j];
                    if(!k)break;
                }
                if(k){
                    can = true;
                    break;
                }
            }
        }
        cout << (can?"YES":"NO") << endl;
    }
    return 0;
}