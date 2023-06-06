#include <bits/stdc++.h>
using namespace std;

int s[55];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int l;
	cin >> l;

	for (int i = 0; i < l; i++)
		cin >> s[i];

	sort(s, s + l);

	int n;
	cin >> n;

	int idx = lower_bound(s, s + l, n) - s;
	int st = s[idx - 1], en = s[idx];

	int cnt = 0;
	for (int i = st + 1; i <= n; i++) {
		for (int j = n; j < en; j++) {
			if (i != j) cnt++;
		}
	}
	cout << cnt;
}