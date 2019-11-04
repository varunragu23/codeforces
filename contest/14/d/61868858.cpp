#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
#define PB push_back
 
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef map<int, int> MAP;
typedef vector<MAP> Vmap;
 
int N;
Mi net;
 
Vmap calcp;
int prof(int n, int m) {
    if (calcp[n].find(m) != calcp[n].end()) return calcp[n][m];
    int maxi = 0;
    for (int i = 0; i < net[n].size(); ++i)
        if (net[n][i] != m) maxi = max(maxi, 1 + prof(net[n][i], n));
    return calcp[n][m] = maxi;
}
 
int f(int n, int m, int q) {
    int maxi = q + prof(n, m);
    int h1 = 0, h2 = 0, n1 = -1, n2 = -1;
    for (int i = 0; i < net[n].size(); ++i) {
        if (net[n][i] != m) {
            int h = prof(net[n][i], n) + 1;
            if (h > h1) {
                h2 = h1;
                n2 = n1;
                h1 = h;
                n1 = net[n][i];
            }
            else if (h > h2) {
                h2 = h;
                n2 = net[n][i];
            }
        }
    }
//     if (n == 1) {
//         cerr << "H1 " << h1 << endl;
//         cerr << "H2 " << h2 << endl;
//     }
    for (int i = 0; i < net[n].size(); ++i) {
        if (net[n][i] != m) {
            int qq = q + 1;
            if (net[n][i] != n1) qq = max(qq, h1 + 1);
            else qq = max(qq, h2 + 1);
            maxi = max(maxi, f(net[n][i], n, qq));
        }
    }
    return maxi;
}
 
int main() {
    cin >> N;
    net = Mi(N);
    for (int i = 1; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        net[a].PB(b);
        net[b].PB(a);
    }
    int maxi = 0;
    calcp = Vmap(N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < net[i].size(); ++j)
            if (i < net[i][j]) {
//                 cerr << "(" << i << ", " << net[i][j] << ") ";
//                 cerr << f(i, net[i][j], 0);
//                 cerr << ' ' << f(net[i][j], i, 0) << endl;
                maxi = max(maxi, f(i, net[i][j], 0)*f(net[i][j], i, 0));
            }
    cout << maxi << endl;
}