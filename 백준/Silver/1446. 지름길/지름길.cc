#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[10005];
vector<pair<int, int>> v[10005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	memset(d, 0x7f7f7f7f, sizeof(d));
	d[0] = 0;

	for (int i = 1; i <= n; i++) {
		int a, b, c; //시작, 도착, 길이
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}

	for (int i = 1; i <= m; i++) {
		d[i] = min(d[i], d[i - 1] + 1);
		for (auto x : v[i-1]) 
			d[x.first] = min(d[x.first], d[i - 1] + x.second);
	}
	cout << d[m];
}