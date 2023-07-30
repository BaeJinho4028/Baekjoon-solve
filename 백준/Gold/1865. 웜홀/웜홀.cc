#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int n, m, w;
vector <pair<pair<int, int>, int>> v;
int dist[505];

void bf() {
	for (int i = 0; i < n; i++) {
		for (auto x : v) {
			int a = x.X.X;
			int b = x.X.Y;
			int c = x.Y;

			if (dist[a] + c < dist[b]) dist[b] = dist[a] + c;
		}
	}

	for (auto x : v) {
		int a = x.X.X;
		int b = x.X.Y;
		int c = x.Y;

		if (dist[a] + c < dist[b]) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m >> w;

		memset(dist, '????', sizeof(dist));
		v.clear();

		while (m--) {
			int a, b, c;
			cin >> a >> b >> c;

			v.push_back({ {a, b}, c });
			v.push_back({ {b, a}, c });
		}

		while (w--) {
			int a, b, c;
			cin >> a >> b >> c;

			v.push_back({ {a, b}, -c });
		}

		bf();
	}
}