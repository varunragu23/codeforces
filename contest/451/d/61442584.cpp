#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
 
pair<LL, LL> solve(string s)
{
      LL ansEven = 0, ansOdd = 0;
      int cntEven[2], cntOdd[2];
      cntEven[0] = cntEven[1] = cntOdd[0] = cntOdd[1] = 0;
      for (int i = 0; i < s.size(); i++)
      {
            ansOdd++;
            int id = s[i] - 'a';
            if (i % 2 == 0)
            {
                  ansOdd += cntEven[id];
                  ansEven += cntOdd[id];
                  cntEven[id]++;
            }
            else
            {
                  ansOdd += cntOdd[id];
                  ansEven += cntEven[id];
                  cntOdd[id]++;
            }
      }
      return make_pair(ansEven, ansOdd);
}
 
 
int main()
{
      srand(time(NULL));
	
	string s;
	cin >> s;
	pair<long long, long long> ans = solve(s);
	cout << ans.first << " " << ans.second << endl;
      
      return 0;
}