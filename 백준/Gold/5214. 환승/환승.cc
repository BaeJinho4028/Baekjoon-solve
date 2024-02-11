#include <bits/stdc++.h>
using namespace std;

vector<int> e[200005];
int dist[200005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, m;
	cin >> n >> k >> m;

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			e[x].push_back(100000 + i);
			e[100000 + i].push_back(x);
		}
	}

	queue<int> q;
	q.push(1);
	dist[1] = 1;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		if (cur == n) {
			cout << dist[n];
			return 0;
		}

		for (auto nxt : e[cur]) {
			if (dist[nxt]) continue;
			if (nxt > 100000) dist[nxt] = dist[cur] + 1;
			else dist[nxt] = dist[cur];
			q.push(nxt);
		}
	}

	cout << -1;
}