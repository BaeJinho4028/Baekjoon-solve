#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int n, k;
bool vis[100005];
int p[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	queue<pair<int,int>> q;
	q.push({ n, 0 });
	vis[n] = true;

	vector<int> path;
	int time = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (auto nxt : { cur.X - 1, cur.X + 1, 2 * cur.X }) {
			if (nxt < 0 || nxt >100000) continue;
			if (vis[nxt]) continue;
			q.push({ nxt, cur.Y + 1 });
			vis[nxt] = true;
			p[nxt] = cur.X;

			if (nxt == k) {
				time = cur.Y + 1;

				int idx = nxt;
				while (idx != n) {
					path.push_back(idx);
					idx = p[idx];
				}

				while (!q.empty())
					q.pop();

				break;
			}
		}
	}

	cout << time << '\n';

	path.push_back(n);
	reverse(path.begin(), path.end());
	for (auto c : path)
		cout << c << ' ';

	return 0;
}