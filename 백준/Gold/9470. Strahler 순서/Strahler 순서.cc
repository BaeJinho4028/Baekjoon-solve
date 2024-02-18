#include <bits/stdc++.h>
using namespace std;

int deg[1005];
int st[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int k, m, p;
		cin >> k >> m >> p;

		int mx = 0;
		vector<int> e[1005];

		while (p--) {
			int a, b;
			cin >> a >> b;
			e[a].push_back(b);
			deg[b]++;
		}

		queue<int> q;
		vector<int> chk[1005];

		for (int i = 1; i <= m; i++) {
			if (deg[i] == 0) {
				q.push(i);
				st[i] = 1;
			}
		}

		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (auto nxt : e[cur]) {

				chk[nxt].push_back(st[cur]);

				if (--deg[nxt] == 0) {
					q.push(nxt);

					int i = 1;
					for (auto x : chk[nxt])
						i = max(i, x);
					int cnt = 0;
					for (auto x : chk[nxt])
						if (i == x) cnt++;

					if (cnt == 1) st[nxt] = i;
					if (cnt >= 2) st[nxt] = i + 1;
				}
			}
		}

		for (int i = 1; i <= m; i++) {
			mx = max(mx, st[i]);
		}

		cout << k << ' ' << mx << '\n';

		memset(deg, 0, sizeof(deg));
		memset(st, 0, sizeof(st));
	}
}