#include <bits/stdc++.h>
using namespace std;

long long d[120];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	d[1] = d[2] = d[3] = 1;

	for (int i = 4; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 3];
	}

	cout << d[n];
}