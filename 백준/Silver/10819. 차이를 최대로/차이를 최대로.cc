#include <bits/stdc++.h>
using namespace std;

int n;
int a[10], b[10];
bool vis[10];
int ans;

void solve(int cur) {
	if (cur == n) {
		int sum = 0;

		for (int i = 0; i < n - 1; i++) {
			sum += abs(b[i] - b[i + 1]);
		}
		ans = max(ans, sum);

		return;
	}

	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;

		vis[i] = true;
		b[cur] = a[i];
		solve(cur + 1);
		vis[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	solve(0);

	cout << ans;
}