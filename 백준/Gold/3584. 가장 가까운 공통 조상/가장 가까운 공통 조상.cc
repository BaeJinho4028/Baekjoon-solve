#include <bits/stdc++.h>
using namespace std;

int n;
int d[10005], p[10005];
vector<int> e[10005];

int NCA(int a, int b) {
	if (d[a] < d[b]) swap(a, b);

	while (d[a] > d[b]) {
		a = p[a];
	}

	while (a != b) {
		a = p[a];
		b = p[b];
	}

	return a;
}

void dfs(int x) {
	for (auto nxt : e[x]) {
		d[nxt] = d[x] + 1;
		dfs(nxt);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 0; i <= n; i++) {
			e[i].clear();
			p[i] = i;
		}

		int a, b;
		for (int i = 0; i < n - 1; i++) {
			cin >> a >> b;
			e[a].push_back(b);
			p[b] = a;
		}

		for (int i = 1; i <= n; i++) {
			if (p[i] == i) {
				d[i] = 0;
				dfs(i);
				break;
			}
		}

		cin >> a >> b;
		cout << NCA(a, b) << '\n';
	}

}