#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v[10005];

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		v[y].push_back(x);
	}

	long long ans = 0;

	for (int i = 1; i <= n; i++) { //색
		if (v[i].size() < 2) continue;

		sort(v[i].begin(), v[i].end());

		for (int j = 0; j < v[i].size(); j++) {
			if (j == 0) //시작점
				ans += v[i][j + 1] - v[i][j];
			else if (j == v[i].size() - 1) //끝점
				ans += v[i][j] - v[i][j - 1];
			else
				ans += min(v[i][j + 1] - v[i][j], v[i][j] - v[i][j - 1]);
		}
	}

	cout << ans;
}