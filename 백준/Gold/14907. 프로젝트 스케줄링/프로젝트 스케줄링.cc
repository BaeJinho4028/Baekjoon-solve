#include <bits/stdc++.h>
using namespace std;

int cost[30], d[30];
vector<int> adj[30];
int deg[30];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int cnt = 0;
	while (getline(cin, s)) {
		int a = s[0] - 'A';
		
		string num = "";
		int i = 2;
		for (; i < s.size() && s[i] != ' '; i++) {
			num += s[i];
		}
		cost[a] = stoi(num);

		for (++i; i < s.size(); i++) {
			adj[s[i] - 'A'].push_back(a);
			deg[a]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < 26; i++) {
		if (cost[i] && !deg[i]) {
			d[i] = cost[i];
			q.push(i);
		}
	}
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (auto nxt : adj[cur]) {
			d[nxt] = max(d[nxt], d[cur] + cost[nxt]);

			if (--deg[nxt] == 0) q.push(nxt);
		}
	}

	int ans = 0;
	for (int i = 0; i < 26; i++)
		ans = max(ans, d[i]);
	cout << ans;
}