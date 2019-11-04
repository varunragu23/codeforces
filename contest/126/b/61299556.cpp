#include <bits/stdc++.h>
 
using namespace std;
 
int exist(string s) {
  int n = s.length();
  vector <int> z(n);
  int l = 0, r = 0;
  for(int i = 1; i < n; i++) {
    if(i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }
    while(i + z[i] < n and s[i + z[i]] == s[z[i]]) z[i]++;
    if(i + z[i] - 1 > r) {
      l = i, r = i + z[i] - 1;
    }
  }
  int mx = 0;
  for(int i = 0; i < n; i++) {
    if(i + z[i] == n and mx >= n - i) return n - i;
    mx = max(mx, z[i]);
  }
  return -1;
}
 
 
int main() {
  string x; cin >> x;
  if(exist(x) == -1) {
    puts("Just a legend");
    return 0;
  }
  cout << x.substr(0, exist(x));
}