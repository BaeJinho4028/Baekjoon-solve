#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int a[100001];
	bool b[2000001] = { 0, };
	int x, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> x;

	for (int i = 0; i < n; i++) {
		if (x - a[i] > 0 && b[x - a[i]]) cnt++;
		b[a[i]] = true;
	}
	cout << cnt;
}