#include <bits/stdc++.h>
using namespace std;

vector<int> p(1005, -1);
tuple<int, int, int> edge[100005];
int cnt, ans;

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool dif(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return 0;

	if (p[u] == p[v]) p[u]--;
	if (p[u] < p[v]) p[v] = u;
	else p[u] = v;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		edge[i] = { cost, a, b };
	}
	sort(edge, edge + m);

	for (int i = 0; i < m; i++) {
		int a, b, cost;
		tie(cost, a, b) = edge[i];

		if (!dif(a, b)) continue;
		ans += cost;
		cnt++;
		if (cnt == n - 1)break;
	}

	cout << ans;
}