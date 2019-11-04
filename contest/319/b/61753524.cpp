#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
using namespace std;
 
const int sz = 100005;
int a[sz], Next[sz], Prev[sz];
 
int check[2][sz], m[2] = {0, 0}, k = 0;
int killed[sz], kills = 0;
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
 
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i + 1 < n; i++)
    {
        Next[i] = i + 1;
        Prev[i + 1] = i;
        if (a[i] > a[i + 1])
            check[0][m[0]++] = i;
    }
    Next[n - 1] = Prev[0] = n;
    a[n] = -1;
 
    bool OK = 1;
    while (OK)
    {
        OK = 0;
        for (int i = 0; i < m[k]; i++)
        {
            int v = check[k][i], u = Next[v];
            if (a[u] != -1 && a[v] > a[u])
            {
                check[1 - k][m[1 - k]++] = v;
                OK = 1;
                killed[kills++] = u;
            }
        }
        for (int i = 0; i < kills; i++)
        {
            int v = killed[i];
            Next[Prev[v]] = Next[v];
            Prev[Next[v]] = Prev[v];
            a[v] = -1;
        }
 
        m[k] = 0;
        k = 1 - k;
        kills = 0;
        ans++;
    }
 
    cout << ans - 1;
}