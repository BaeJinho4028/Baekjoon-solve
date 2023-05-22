#include <bits/stdc++.h>
using namespace std;

int h[10005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	sort(h, h + n);

	for (int i = 0; i < n; i++) {
		if (l >= h[i]) l++;
	}

	cout << l;
}