#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int p[3005];

int f(int x) {
	if (p[x]<0) return x;
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
	
	int t;
	cin >> t;
	while (t--) {
		memset(p, -1, sizeof(p));
		vector<pair<pair<int, int>, int>> v;

		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			int x, y, r;
			cin >> x >> y >> r;

			v.push_back({ {x, y}, r });
		}

		int ans = n;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				long long a = (v[i].X.X - v[j].X.X) * (v[i].X.X - v[j].X.X) + (v[i].X.Y - v[j].X.Y) * (v[i].X.Y - v[j].X.Y);
				long long b = (v[i].Y + v[j].Y) * (v[i].Y + v[j].Y);
				if (a <= b && dif(i, j)) ans--;
			}
		}

		cout << ans << '\n';
	}
}