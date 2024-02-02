#include <bits/stdc++.h>
using namespace std;

string s;
string b[2];

int d[2][105][25];

int f(int ad, int cur, int cnt) {
	if (cnt == s.size()) return 1;

	int& ret = d[ad][cur][cnt];
	if (~ret) return ret;

	ret = 0;

	for (int i = cur; i < b[0].size(); i++) {
		if (b[ad][i] == s[cnt]) {
			ret += f(!ad, i + 1, cnt + 1);
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> b[0] >> b[1];

	memset(d, -1, sizeof(d));

	cout << f(0, 0, 0) + f(1, 0, 0);

	return 0;
}