#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int g[200005]; //선물 받은수
bool chk[200005];
pair<int, int> p[200005]; // 선물 준 목록

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		g[a]++; g[b]++;
		p[i] = { a, b };
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (g[i] < 2) {
			chk[i] = true;
			q.push(i);
		}
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int a = p[cur].X;
		int b = p[cur].Y;
		if (--g[a] < 2 && !chk[a]) {
			chk[a] = true;
			q.push(a);
		}
		if (--g[b] < 2 && !chk[b]) {
			chk[b] = true;
			q.push(b);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!chk[i]) cnt++;
	}

	cout << cnt << '\n';
	for (int i = 1; i <= n; i++) {
		if (chk[i]) continue;
		cout << i << ' ';
	}
}