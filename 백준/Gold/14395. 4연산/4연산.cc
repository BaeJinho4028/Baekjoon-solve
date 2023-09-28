#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second
const int INF = 1000000000;

ll s, t;
map<ll, ll> vis;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> t;

	if (s == t) {
		cout << 0;
		return 0;
	}

	queue<pair<ll, string>> q;
	q.push({ s, "" });
	vis[s]++;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		if (cur.X == t) {
			cout << cur.Y;
			return 0;
		}

		if (vis[cur.X * cur.X] == 0) {
			vis[cur.X * cur.X]++;
			q.push({ cur.X * cur.X, cur.Y + "*" });
		}

		if (vis[cur.X + cur.X] == 0) {
			vis[cur.X + cur.X]++;
			q.push({ cur.X + cur.X, cur.Y + "+" });
		}

		if (vis[cur.X - cur.X] == 0) {
			vis[cur.X - cur.X]++;
			q.push({ cur.X - cur.X, cur.Y + "-" });
		}

		if (cur.X != 0 && vis[cur.X / cur.X] == 0) {
			vis[cur.X / cur.X]++;
			q.push({ cur.X / cur.X, cur.Y + "/" });
		}
	}

	cout << -1;
}