#include <bits/stdc++.h>
using namespace std;

const int MX = 1000 * 15 + 5;
map<string, int> nxt[MX];
int root = 1;
int unused = 2;

void insert(vector<string>& v) {
	int cur = root;
	for (auto s : v) {
		if (!nxt[cur][s])
			nxt[cur][s] = unused++;
		cur = nxt[cur][s];
	}
}

void dfs(int cur, int d) {
	for (auto nx : nxt[cur]) {
		string level;
		for (int i = 0; i < d; i++)
			level += "--";
		cout << level << nx.first << '\n';
		dfs(nx.second, d + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		vector<string> s(k);
		for (int i = 0; i < k; i++) {
			cin >> s[i];
		}
		insert(s);
	}
	dfs(1, 0);
}