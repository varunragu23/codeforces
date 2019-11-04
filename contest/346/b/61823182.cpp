#include <algorithm>
#include <iostream>
#include <iomanip>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,102400000")
 
int nA, nB, nVirus;
string A, B, virus;
int trans[101][26];
 
string prefix(string A, int len)
{
	string ret;
	for(int i = 0; i < len; i++)
		ret += A[i];
	return ret;
}
 
bool endWith(string A, string pat)
{
	if(A.length() < pat.length()) return false;
	for(int i = 0; i < pat.length(); i++)
		if(A[i - (int)pat.length() + (int)A.length()] != pat[i])
			return false;
	return true;
}
 
int getStateID(string s)
{
	int ret = 0;
	for(int i = 1; i <= nVirus; i++)
		if(endWith(s, prefix(virus, i)))
			ret = i;
	return ret;
}
 
int F[101][101][101];
int nex1[101][101][101];
int nex2[101][101][101];
int nex3[101][101][101];
string nex0[101][101][101];
int done[101][101][101];
 
int f(int pA, int pB, int state)
{
	if(state == nVirus) return -10000;
	if(pA == nA && pB == nB) return 0;
	if(done[pA][pB][state]) return F[pA][pB][state];
	int &ret = F[pA][pB][state];
	ret = -10000;
	done[pA][pB][state] = true;
	if(pA != nA)
	{
		int v = f(pA + 1, pB, state);
		if(v > ret)
		{
			ret = v;
			nex1[pA][pB][state] = pA + 1;
			nex2[pA][pB][state] = pB;
			nex3[pA][pB][state] = state;
			nex0[pA][pB][state] = "";
		}
	}
	if(pB != nB)
	{
		int v = f(pA, pB + 1, state);
		if(v > ret)
		{
			ret = v;
			nex1[pA][pB][state] = pA;
			nex2[pA][pB][state] = pB + 1;
			nex3[pA][pB][state] = state;
			nex0[pA][pB][state] = "";
		}
	}
	if(pA != nA && pB != nB && A[pA] == B[pB])
	{
		int v = 1 + f(pA + 1, pB + 1, trans[state][A[pA]-'A']);
		if(v > ret)
		{
			ret = v;
			nex1[pA][pB][state] = pA + 1;
			nex2[pA][pB][state] = pB + 1;
			nex3[pA][pB][state] = trans[state][A[pA]-'A'];
			nex0[pA][pB][state] = A[pA];
		}
	}
	
	return ret;
}
 
int MAIN()
{
	cin >> A >> B >> virus;
	nA = A.length();
	nB = B.length();
	nVirus = virus.length();
	memset(nex1, 0xff, sizeof(nex1));
	for(int i = 0; i < nVirus; i++)
		for(int j = 0; j < 26; j++)
			trans[i][j] = getStateID(prefix(virus, i) + char('A' + j));
	memset(done, 0, sizeof(done));
	int ans = f(0, 0, 0);
	if(ans == 0)
		cout << ans << endl;
	else
	{
		int arg1 = 0;
		int arg2 = 0;
		int arg3 = 0;
		string ansString;
		while(nex1[arg1][arg2][arg3] != -1)
		{
			ansString += nex0[arg1][arg2][arg3];
			int nextArg1 = nex1[arg1][arg2][arg3];
			int nextArg2 = nex2[arg1][arg2][arg3];
			int nextArg3 = nex3[arg1][arg2][arg3];
			arg1 = nextArg1;
			arg2 = nextArg2;
			arg3 = nextArg3;
		}
		cout << ansString << endl;
	}
 
	
	return 0;
}
 
int main()
{
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}