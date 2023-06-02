#include <bits/stdc++.h>
using namespace std;

int a[505], ans;

int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<pair<int, int>> st;

	int h, w;
	cin >> h >> w;

	for (int i = 0; i < w; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < w - 1; i++) {
		int l = 0, r = 0;

		for (int j = 0; j < i; j++) l = max(l, a[j]);
		for (int j = i + 1; j < w; j++) r = max(r, a[j]);

		ans += max(0, min(l, r) - a[i]);
	}

	cout << ans;
}
