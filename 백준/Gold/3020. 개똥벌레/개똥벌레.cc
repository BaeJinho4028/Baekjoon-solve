#include <bits/stdc++.h>
using namespace std;

int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> bottom(n / 2), top(n / 2);
	for (int i = 0; i < n / 2; i++)
		cin >> bottom[i] >> top[i];

	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());

	int ans = 0x7f7f7f7f, cnt = 0;

	for (int i = 1; i <= m; i++) {
		int tmp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
		tmp += top.size() - (upper_bound(top.begin(), top.end(), m - i) - top.begin());

		if (ans > tmp) {
			ans = tmp;
			cnt = 0;
		}
		if (ans == tmp)
			cnt++;
	}

	cout << ans << ' ' << cnt;
}