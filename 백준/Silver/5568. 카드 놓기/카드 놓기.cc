#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[15];
bool vis[15];
set<int> se;

void solve(int cur, string s) {
	if (cur == k) {
		se.insert(stoi(s));
		return;
	}

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		vis[i] = true;
		solve(cur + 1, s + to_string(a[i]));
		vis[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	solve(0, "");

	cout << se.size();
}