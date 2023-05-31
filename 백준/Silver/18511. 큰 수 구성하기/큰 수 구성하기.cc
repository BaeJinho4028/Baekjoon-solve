#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
vector<int> v;

void dfs(int num, int ten) {
	if (n < num) return;

	ans = max(ans, num);

	for (int i = 0; i < v.size(); i++)
		dfs(num + v[i] * ten, ten * 10);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	dfs(0, 1);

	cout << ans;
}
