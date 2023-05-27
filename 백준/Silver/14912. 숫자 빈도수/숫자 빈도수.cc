#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	char c;
	int n, cnt = 0;

	cin >> n >> c;

	for (int i = 1; i <= n; i++) {
		s = to_string(i);
		for(int j=0; j< s.size(); j++)
			if (s[j] == c) cnt++;
	}

	cout << cnt;
}