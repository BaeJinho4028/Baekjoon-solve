#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;
int d[100005][5][5];

int chk(int from, int to) {
	if (from == 0) return 2;
	if (from == to) return 1;
	if (abs(from - to) == 2) return 4;
	return 3;
}

int f(int cur, int l, int r) {
	if (cur == v.size()) return 0;
	if (l == r && l != 0) return '????';

	int& ret = d[cur][l][r];
	if (~ret) return ret;

	ret = min(f(cur + 1, v[cur], r) + chk(l, v[cur]),
		f(cur + 1, l, v[cur]) + chk(r, v[cur]));

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a;
	while (cin >> a) {
		if (a == 0) break;
		v.push_back(a);
	}

	memset(d, -1, sizeof(d));
	cout << f(0, 0, 0);
}