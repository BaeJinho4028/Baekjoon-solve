#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

string s;

int f() {
	int len = s.size();

	for (int i = 0; i < len / 2; i++) 
		if (s[i] != s[len - i - 1])
			return len;
	
	for (int i = 1; i < len; i++)
		if (s[0] != s[i])
			return len - 1;

	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	cout << f();
}