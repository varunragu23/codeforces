#include <iostream>
#include <fstream>
#include <vector>
#include <string>
 
using namespace std;
 
int a, b, c;
int m[100001];
int z[100001];
string s;
vector<pair<int, int> > ans;
 
int main(){
    cin >> s;
    int n = 0;
    int last = -1;
    for(int i = 1; i < s.size(); ++i){
      if(last > i) z[i] = min(z[i - n], last - i);
      while(i + z[i] < s.size() && s[i + z[i]] == s[z[i]]) ++z[i];
      if(i + z[i] > last) last = i + z[i], n = i;
    }
   // for(int i = 0; i < s.size(); ++i)
    //  cout << z[i] << ' ';
    z[0] = s.size();
    for(int i = 0; i < s.size(); ++i) m[z[i]]++;
    for(int i = s.size(); i > 0; --i)
      m[i - 1] += m[i];
    for(int i = 1; i <= s.size(); ++i){
      if(z[s.size() - i] == i)
	ans.push_back(make_pair(i, m[i]));
    }
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); ++i)
      cout << ans[i].first << ' ' << ans[i].second << "\n";
  
    return 0;
}
