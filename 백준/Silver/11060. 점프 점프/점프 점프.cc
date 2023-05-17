#include <bits/stdc++.h>
using namespace std;

int a[1005];
int dist[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	fill(dist, dist + n, 0x7f7f7f7f);
	queue<int> q;
	q.push(0);
	dist[0] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int nxt = cur; nxt <= cur + a[cur]; nxt++) {
			if (nxt >= n) continue;
			if (dist[nxt] > dist[cur] + 1) {
				dist[nxt] = dist[cur] + 1;
				q.push(nxt);
			}
		}
	}

	if (dist[n - 1] == 0x7f7f7f7f) cout << -1;
	else cout << dist[n-1];
}