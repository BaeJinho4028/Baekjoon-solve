#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int n, m, mn = 0x7f7f7f7f;
bool vis[15];
vector<pair<int, int>> h, c, p;

void check() {
	int result = 0;
	for (int i = 0; i < h.size(); i++) {
		int tmp = 0x7f7f7f7f;
		for (int j = 0; j < p.size(); j++) {
			tmp = min(tmp, ( abs(h[i].X - p[j].X) + abs(h[i].Y - p[j].Y) ));
		}
		result += tmp;
	}
	mn = min(mn, result);
}

void solve(int x, int cur) {
	if (cur == m) {
		check();
	}

	for (int i = x; i < c.size(); i++) {
		if (vis[i]) continue;

		vis[i] = true;
		p.push_back(c[i]);
		solve(i, cur + 1);
		vis[i] = false;
		p.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			if (x == 1) h.push_back({ i, j });
			if (x == 2) c.push_back({ i, j });
		}
	}

	solve(0, 0);

	cout << mn;
}