#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int mod{100000000};
long long int dp[101][101][11][11];
int main(){
    memset(dp, 0, sizeof dp);
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    for(int rem_foot{0}; rem_foot <= n1; ++rem_foot){
        for(int rem_horse{0}; rem_horse <= n2; ++rem_horse){
            for(int cons_f{0}; cons_f <= k1; ++cons_f){
                for(int cons_h{0}; cons_h <= k2; ++cons_h){
                    long long int ans{0};
                    if(rem_foot + rem_horse == 0){
                        ans = 1;
                    } else {
                        if(rem_foot > 0 and cons_f > 0){
                            ans += dp[rem_foot - 1][rem_horse][cons_f - 1][k2];
                            ans %= mod;
                        }
                        if(rem_horse > 0 and cons_h > 0){
                            ans += dp[rem_foot][rem_horse - 1][k1][cons_h - 1];
                            ans %= mod;
                        }
                    }
                    dp[rem_foot][rem_horse][cons_f][cons_h] = ans;
                }
            }
        }
    }

    cout << dp[n1][n2][k1][k2] << endl;

    return 0;
}