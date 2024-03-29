#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
 
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>
#include <complex>
 
using namespace std;
 
#pragma comment(linker, "/STACK:200000000")
 
typedef long long int64;
 
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) (int(a.size()) - 1)
#define all(a) a.begin(), a.end()
 
const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;
 
int div(double a, double b) {
    if (abs(a) < EPS)
        return 0;
    if (a < 0)
        return -div(-a, b) - 1;
    return int(a / (2 * b) + EPS);
}
 
void norm(double &x, double a) {
    int i = div(x, a);
    x -= i * 2 * a;
    if (x > a)
        x = 2 * a - x;
}
 
int main() {
#ifdef RADs_project
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    double a, b, m, vx, vy, vz;
    cin >> a >> b >> m >> vx >> vy >> vz;
 
    double t = -m / vy;
 
    double x = t * vx + a / 2;
    double z = t * vz;
 
    norm(x, a); 
    norm(z, b);
 
    printf("%.20lf %.20lf\n", x, z);
    
    return 0;
}