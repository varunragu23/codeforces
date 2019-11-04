/*
ID: varunra2
LANG: C++
TASK: dimabacter
*/
#pragma region Headers, define, typedef
#include<bits/stdc++.h>

using namespace std;
#ifdef DEBUG
#include <debug.h>
#endif

#define EPS 1e-9
#define IN(A, B, C) assert(B <= A && A <= C)
#define INF (int)1e9
#define MEM(a, b) memset(a, (b), sizeof(a))
#define MOD 1000000007
#define MP make_pair
#define PB push_back
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()

const double PI = acos(-1.0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef map<int, int> MPII;
typedef multiset<int> MSETI;
typedef set<int> SETI;
typedef set<string> SETS;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<string> VS;

#define deb(x) cerr << #x << " = " << x << endl;


// util functions

#pragma endregion
int _lis( int arr[], int n, int *max_ref) 
{ 
    /* Base case */
    if (n == 1) 
        return 1; 
  
    // 'max_ending_here' is length of LIS ending with arr[n-1] 
    int res, max_ending_here = 1;  
  
    /* Recursively get all LIS ending with arr[0], arr[1] ... 
       arr[n-2]. If   arr[i-1] is smaller than arr[n-1], and 
       max ending with arr[n-1] needs to be updated, then 
       update it */
    for (int i = 1; i < n; i++) 
    { 
        res = _lis(arr, i, max_ref); 
        if (arr[i-1] < arr[n-1] && res + 1 > max_ending_here) 
            max_ending_here = res + 1; 
    } 
  
    // Compare max_ending_here with the overall max. And 
    // update the overall max if needed 
    if (*max_ref < max_ending_here) 
       *max_ref = max_ending_here; 
  
    // Return length of LIS ending with arr[n-1] 
    return max_ending_here; 
} 
  
// The wrapper function for _lis() 
int lis(VI& arr, int n) 
{ 
    // The max variable holds the result 
    int max = 1; 
    int ps[n];
    for(int i = 0; i < n; i++) {
      ps[i] = arr[i];
    }
    // The function _lis() stores its result in max 
    _lis( ps, n, &max ); 
  
    // returns max 
    return max; 
} 

static bool comp(pair<int, ld>& a, pair<int, ld>& b) {
  return b.second > a.second;
}

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
  freopen("dimabacter.in", "r", stdin);    
  freopen("dimabacter.out", "w", stdout); 
#endif
  cin.sync_with_stdio(0); cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<pair<int, ld>> vals(n);

  for(int i = 0; i < n; i++) {
    cin >> vals[i].first >> vals[i].second;
  }

  sort(vals.begin(), vals.end(), comp);

  VI arr(n);

  for(int i = 0; i < n; i++) {
    arr[i] = vals[i].first;
  }

  VI dp(n, 0);

  for(int i = 0; i < n; i++) {
    dp[i] = 1;
    for(int j = 0; j < i; j++) {
      if(arr[j] <= arr[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
      
    }
  }

  cout << n - *max_element(dp.begin(), dp.end()) << endl;

 
  return 0;
}
