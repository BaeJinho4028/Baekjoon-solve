#include <bits/stdc++.h>
using namespace std;

int n;
int p[300005];

int f(int x) {
	if (p[x] < 0) return x;
	return p[x] = f(p[x]);
}

bool dif(int u, int v) {
	u = f(u); v = f(v);
	if (u == v) return 0;
	p[u] = v;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	memset(p, -1, sizeof(p));

	for (int i = 0; i < n - 2; i++) {
		int a, b;
		cin >> a >> b;
		dif(a, b);
	}

	for (int i = 1; i < n; i++) {
		if (dif(i, i+1)) cout << i << ' ' << i+1 << '\n';
	}
}