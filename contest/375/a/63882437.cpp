#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
 
int main() {
	string a;
	cin >> a;
	string last = "1689";
	for (int i = 0; i < last.size(); ++i) {
		a.erase(find(a.begin(), a.end(), last[i]));
	}
	if (count(a.begin(), a.end(), '0') == a.size()) {
		cout << "1869" << a << endl;
		return 0;
	}
	sort(a.rbegin(), a.rend());
	do {
		string t = a + last;
		int ret = 0;
		for (int i = 0; i < t.size(); ++i) {
			ret = ret * 10 + t[i] - '0';
			ret %= 7;
		}
		if (ret == 0) {
			cout << t << endl;
			return 0;
		}
	} while (next_permutation(last.begin(), last.end()));
}