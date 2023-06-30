#include <bits/stdc++.h>
using namespace std;

bool prime[10005];
int dist[10005];

void isPrime() {
	memset(prime, true, sizeof(prime));
	for (int i = 2; i * i < 10005; i++) {
		for (int j = i + i; j < 10005; j += i) {
			prime[j] = false;
		}
	}
}

bool bfs(int a, int b) {
	queue<int> q;
	q.push(a);
	dist[a] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		if (cur == b) {
			cout << dist[cur] << '\n';
			return true;
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				string s = to_string(cur);
				s[i] = j + '0';
				int nxt = stoi(s);

				if (nxt >= 10000 || nxt < 1000) continue;
				if (!prime[nxt] || dist[nxt] != -1)continue;

				dist[nxt] = dist[cur] + 1;
				q.push(nxt);
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	isPrime();

	while (t--) {
		int a, b;
		cin >> a >> b;

		memset(dist, -1, sizeof(dist));

		if (!bfs(a, b)) cout << "Impossible\n";
	}
}