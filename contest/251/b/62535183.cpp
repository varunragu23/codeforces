#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
const int sh = 102;
 
struct point {
    int p[200];
};
 
point m[300];
int us[300];
int sum[300];
point q, s, f;
int n, k;
 
typedef long long ll;
 
bool eq(point a, point b) {
    for (int i = 1; i <= n; i++)
        if (a.p[i] != b.p[i])
            return false;
    return true;
}
 
point make1(point a) {
    point b;
    for (int i = 1; i <= n; i++)
        b.p[i] = a.p[q.p[i]];
    return b;
}
 
point make2(point a) {
    point b;
    for (int i = 1; i <= n; i++)
        b.p[q.p[i]] = a.p[i];
    return b;
}
 
void wr(point a) {
    cout << "WR" << endl;
    for (int i = 1; i <= n; i++)
        cout << a.p[i] << ' ';
    cout << endl;
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
 
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> q.p[i];
    for (int i = 1; i <= n; i++)
        cin >> s.p[i];
    for (int i = 1; i <= n; i++)
        f.p[i] = i;
 
    m[0 + sh] = f;
    for (int i = 1; i <= k; i++) {
        m[i + sh] = make1(m[i + sh - 1]);
    }
    //wr(m[0 + sh]);
    for (int i = -1; i >= -k; i--) {
        m[i + sh] = make2(m[i + sh + 1]);
    }
 
    for (int i = -k; i <= k; i++) {
        if (eq(m[i + sh], s))
            us[i + sh] = 1;
     //   cout << us[i + sh] << ' ';
    }
   // cout << endl;
 
    sum[-k - 1 + sh] = 0;
    for (int i = -k; i <= k; i++)
        sum[i + sh] = sum[i + sh - 1] + us[i + sh];
 
    if (us[0 + sh] == 1) {
        cout << "NO" << endl;
        return 0;
    }
 
    for (int i = k; i > 0; i -= 2) {
        if (us[i + sh] == 1) {
            int h = sum[i + sh] - sum[-1 + sh];
            if (h != 1)
                continue;
            if (i == 1 && us[-1 + sh] == 1 && k > i)
                continue;
            cout << "YES" << endl;
            return 0;
        }
    }
 
    for (int i = -k; i < 0; i += 2) {
        if (us[i + sh] == 1) {
            int h = sum[0 + sh] - sum[i + sh - 1];
            if (h != 1)
                continue;
            if (i == -1 && us[1 + sh] == 1 && k > (-i))
                continue;
            cout << "YES" << endl;
            return 0;
        }
    }
 
    cout << "NO";
 
    return 0;
}
