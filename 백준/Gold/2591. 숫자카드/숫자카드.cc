#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int d[45];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	d[0] = 1;

	for (int i = 1; i < s.size(); i++) {
		int tmp = (s[i - 1] - '0') * 10 + (s[i] - '0');
		if (tmp >= 10 && tmp <= 34) {
			if (i == 1)
				d[i] = 1;
			else
				d[i] += d[i - 2];
		}

		if (s[i] != '0')
			d[i] += d[i - 1];
	}

	cout << d[s.size() - 1];
}