#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
vector<pair<int, int>> adj[5005];
int dist[5005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}
	int s, e;
	cin >> s >> e;

	memset(dist, '????', sizeof(dist));

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,s });
	dist[s] = 0;

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		for (auto nxt : adj[cur.Y]) {
			if (dist[nxt.Y] > dist[cur.Y] + nxt.X) {
				dist[nxt.Y] = dist[cur.Y] + nxt.X;
				pq.push({ nxt.X, nxt.Y });
			}
		}
	}

	cout << dist[e];
}