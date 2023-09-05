#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define ll long long
int dx[8] = { 1,0,-1,0, 1, 1, -1, -1 };
int dy[8] = { 0,1,0,-1, 1, -1, 1, -1 };

int n, m;
vector<int> p(200005, -1);
vector<tuple<int,int,int,int>> e;

int ans, cnt, tmp;

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool dif(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return 0;

	p[u] = v;
	return 1;
}

void solve(bool flag) {
	if (n - 1 >= m) {
		cout << "NO";
		exit(0);
	}

	for (int i = 1; i <= n; i++)
		p[i] = -1;

	vector<int> v;
	if (flag) {
		int a, b, c, idx;
		tie(c, a, b, idx) = e[tmp];
		!dif(a, b);
		ans += c;
		v.push_back(idx);
	}

	for (int i = 0; i < e.size(); i++) {
		int a, b, c, idx;
		tie(c, a, b, idx) = e[i];
		if (!dif(a, b)) {
			tmp = i;
			continue;
		}

		if (flag) {
			ans += c;
			v.push_back(idx);
		}
	}

	if (flag) {
		cout << "YES\n";
		sort(v.begin(), v.end());
		for (auto x : v)
			cout << x << ' ';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		e.push_back({ c, a, b, i });
	}
	sort(e.begin(), e.end());

	solve(false);
	solve(true);
}