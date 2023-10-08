#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s, a[105];
int n;
int d[105];

int f(int x) {
	if (x == 0) return 1;

	int& ret = d[x];
	if (~ret) return ret;

	ret = 0;
	for (int i = 1; i <= n; i++) {
		if (x < a[i].size()) continue;
		if (s.substr(x - a[i].size(), a[i].size()) != a[i]) continue;
		d[x] += f(x - a[i].size());
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	memset(d, -1, sizeof(d));
	bool flag = f(s.size());
	cout << flag;
}