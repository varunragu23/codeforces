#include <functional>
#include <algorithm> 
#include <iostream> 
#include <string.h> 
#include <stdlib.h> 
#include <numeric>
#include <sstream> 
#include <fstream>
#include <ctype.h> 
#include <stdio.h> 
#include <bitset>
#include <vector> 
#include <string> 
#include <math.h> 
#include <time.h> 
#include <queue> 
#include <stack> 
#include <list>
#include <map> 
#include <set> 
#define Int long long 
#define INF 0x3F3F3F3F 
#define eps 1e-9
using namespace std;
typedef pair<int, int> pii;
 
#define N 1000009
 
char s[N];
int L[N], R[N];
 
int main()
{
	int a, b, i;
	scanf("%s %d %d", s, &a, &b);
	int n = strlen(s);
	L[0] = (s[0] - '0') % a;
	for (i = 1; i < n; i++)
		L[i] = (L[i - 1] * 10 + s[i] - '0') % a;
	int pw = 1;
	for (i = n - 1; i >= 0; i--, pw = pw * 10 % b)
		R[i] = (R[i + 1] + pw * (s[i] - '0')) % b;
	for (i = 0; i < n - 1; i++)
	{
		if (s[i + 1] != '0' && L[i] == 0 && R[i + 1] == 0)
		{
			puts("YES");
			char tmp = s[i + 1];
			s[i + 1] = 0;
			puts(s);
			s[i + 1] = tmp;
			puts(s + i + 1);
			return 0;
		}
	}
	puts("NO");
}