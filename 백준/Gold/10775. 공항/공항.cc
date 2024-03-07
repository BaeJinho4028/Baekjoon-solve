#include <bits/stdc++.h>
using namespace std;

int p[100005];

int f(int x) {
	if (p[x] == x) return x;
	return p[x] = f(p[x]);
}

bool dif(int u, int v) {
	u = f(u); v = f(v);
	if (u == v) return true;
	p[u] = v;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= 100000; i++)
		p[i] = i;

	int cnt = 0;
	while (m--) {
		int x;
		cin >> x;

		if (f(x) == 0) break;
		dif(f(x), f(x) - 1);
		cnt++;
	}

	cout << cnt;
}