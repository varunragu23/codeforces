#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iomanip>
#include <ctime>
using namespace std;
 
template <typename T>
T next_int() {
    T x = 0, p = 1;
    char ch;
    do { ch = getchar(); } while(ch <= ' ');
    if (ch == '-') {
        p = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * p;
}
 
const int max_n = (int)3e5 + 228;
const int max_int = (int)1e9 + 228;
 
int l[max_n];
int r[max_n];
 
vector<pair<int, pair<int, int> > > a;
 
int t[max_n * 4];
 
void modi(int v, int l, int r, int p, int a) {
	if(l == r) {
		t[v] = a;
		return;
	}
 
	int mid = (l + r) / 2;
	if(p <= mid) modi(v * 2, l, mid, p, a); else modi(v * 2 + 1, mid + 1, r, p, a);
 
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}
 
int get(int v, int l, int r, int _l, int _r) {
	if(_l > _r) return max_int;
	if(l == _l && r == _r) return t[v];
 
	int mid = (l + r) / 2;
	return min(get(v * 2, l, mid, _l, min(mid, _r)),  
		get(v * 2 + 1, mid + 1, r, max(mid + 1, _l), _r));
}
 
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
 
	int n = next_int<int>();
	for(int i = 0; i < n; i++) {
		l[i] = next_int<int>();
		r[i] = next_int<int>();
 
		a.push_back(make_pair(l[i], make_pair(0, i)));
		a.push_back(make_pair(r[i], make_pair(1, i)));
	}
 
	sort(a.begin(), a.end());
 
	int k = 1;
	for(int i = 0; i < a.size(); i++) {
		if(i && a[i].first != a[i - 1].first) k++;
		if(a[i].second.first == 0) l[a[i].second.second] = k; else
			r[a[i].second.second] = k;     	
	}
 
	for(int i = 1; i <= k; i++) modi(1, 1, k, i, max_int);
 
	for(int i = 0; i < n; i++) {
		modi(1, 1, k, r[i], l[i]);
	}
 
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(r[i] + 1 <= k && get(1, 1, k, r[i] + 1, k) < l[i]) ans++;
	}
 
	cout << ans << "\n";
}