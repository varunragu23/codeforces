#include <iostream>
 
using namespace std;
 
long long todec(int b){
  long long res = 0;
  long long m = 1;
  while(b > 0){
    if(b&1)
      res += m;
    m *= 10;
    b >>= 1;
  }
  return res;
}
 
int main(void){
  long long n, k = 1;
  cin >> n;
  while(todec(k+1) <= n)
    ++k;
  cout << k << endl;
 
  return 0;
}