#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
 
using namespace std;
FILE *in; FILE *out;
 
const int MAX = 128;
 
int n;
char a[MAX][MAX];
 
int main(void) {
	in = stdin; out = stdout;
//	in = fopen("A.in", "rt"); out = fopen("A.out", "wt");
	
	int n;
	fscanf(in, "%d", &n);
	for (int i = 0; i < n; i++)
	    fscanf(in, "%s", a[i]);
	
	// Only rows
	map < int, int > q;
	for (int i = 0; i < n; i++) {
	    for (int c = 0; c < n; c++)
	        if (a[i][c] == '.') q[i] = c;
	}
	if ((int)q.size() == n) {
	    for (map <int, int> :: iterator it = q.begin(); it != q.end(); it++)
	        fprintf(out, "%d %d\n", it->first + 1, it->second + 1);
	    return 0;
	}
	
	// Only columns
	q.clear();
	for (int i = 0; i < n; i++) {
	    for (int c = 0; c < n; c++)
	        if (a[c][i] == '.') q[i] = c;
	}
	if ((int)q.size() == n) {
	    for (map <int, int> :: iterator it = q.begin(); it != q.end(); it++)
	        fprintf(out, "%d %d\n", it->second + 1, it->first + 1);
	    return 0;
	}
	fprintf(out, "-1\n");
	return 0;
}