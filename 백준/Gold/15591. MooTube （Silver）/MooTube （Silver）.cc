#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define ll long long
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1};

vector<pair<ll, ll>> e[5005];
ll dist[5005];
bool vis[5005];
int n, m;

int bfs(int k, int v) {
	int cnt = 0;
	queue<pair<ll, ll>> q;

	q.push({ v, '????' });
	dist[v] = 0;
	vis[v] = true;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (auto nxt : e[cur.X]) {
			if (vis[nxt.X]) continue;
			vis[nxt.X] = true;

			if (dist[cur.X] == 0) dist[nxt.X] = nxt.Y;
			else dist[nxt.X] = min(dist[cur.X], nxt.Y);
			q.push({ nxt.X, nxt.Y });
		}
	}

	for (int i = 1; i <= n; i++)
		if (dist[i] >= k) cnt++;

	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a].push_back({ b, c });
		e[b].push_back({ a, c });
	}

	while (m--) {
		int k, v;
		cin >> k >> v;
		memset(dist, '????', sizeof(dist));
		memset(vis, false, sizeof(vis));
		cout << bfs(k, v) << '\n';
	}
}