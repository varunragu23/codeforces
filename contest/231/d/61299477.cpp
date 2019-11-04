#include <iostream>
using namespace std;

int main() {
//  freopen("a.in","r",stdin); freopen("a.out","w",stdout);
    
    int x, y, z;
    cin >> x >> y >> z;
    int dx, dy, dz;
    cin >> dx >> dy >> dz;
    int a1, a2, a3, a4, a5, a6;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    int res = 0;
    if (y < 0) {
        res += a1;
    } else if (y > dy) {
        res += a2;
    }
    if (z < 0) {
        res += a3;
    } else if (z > dz) {
        res += a4;
    }
    if (x < 0) {
        res += a5;
    } else if (x > dx) {
        res += a6;
    }
    cout << res << endl;
}