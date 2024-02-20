#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

vector<pair<int, int>> adj[1005];
int deg[1005];
int dist[1005], p[1005];

void f(int x) {
	if (x == 1) {
		cout << x << ' ';
		return;
	}
	f(p[x]);
	cout << x << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int p, q, r;
		cin >> p >> q >> r;
		adj[p].push_back({ q,r });
		deg[q]++;
	}

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		if (cur == 1 && deg[cur] == 0) break;

		for (auto nxt : adj[cur]) {
			if (dist[nxt.X] < dist[cur] + nxt.Y) {
				dist[nxt.X] = dist[cur] + nxt.Y;
				p[nxt.X] = cur;
			}

			if (--deg[nxt.X] == 0)
				q.push(nxt.X);
		}
	}


	cout << dist[1] << '\n';
	f(p[1]);
	cout << 1;
}