#include <bits/stdc++.h>
using namespace std;

int m, n, l;
int s[100005];
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> l;

	for (int i = 0; i < m; i++)
		cin >> s[i];

	sort(s, s + m);

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int st = 0, en = m - 1;
		while (st <= en) {
			int mid = (st + en) / 2;
			int d = abs(s[mid] - v[i].first) + v[i].second;
			if (d <= l) {
				ans++;
				break;
			}
			else {
				if (v[i].first >= s[mid]) st = mid + 1;
				else en = mid - 1;
			}
		}
	}

	cout << ans;
}