#include <bits/stdc++.h>
using namespace std;

string s[25];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	
	bool in = 1, de = 1;
	for (int i = 0; i < n-1; i++) {
		if (s[i] < s[i+1]) de = 0;
		else in = 0;
	}

	if (!in && !de) cout << "NEITHER";
	else if (in) cout << "INCREASING";
	else cout << "DECREASING";
}