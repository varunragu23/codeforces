#include <iostream>
#include <stdio.h>
#include <set>
#define MOD 1000000007
 
using namespace std;
 
typedef long long LL;
 
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    set<char> SET[m];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            SET[j].insert(s[j]);
    }
    int ans = 1;
    for (int i = 0; i < m; i++)
        ans = LL(ans) * SET[i].size() % MOD;
    printf("%d\n", ans);
    return 0;
}