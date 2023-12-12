#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define ll long long

vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l, k;
	cin >> n >> l >> k;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		v.push_back({ b,a });
	}
	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (k == 0) break;
		if (l >= v[i].X) {
			ans += 140;
			k--;
		}
		else if (l >= v[i].Y) {
			ans += 100;
			k--;
		}
	}
	cout << ans;
}