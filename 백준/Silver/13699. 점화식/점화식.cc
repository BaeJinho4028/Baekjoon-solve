#include <bits/stdc++.h>
using namespace std;

long long d[40];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	d[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			d[i] += d[j] * d[i - j - 1];
		}
	}

	cout << d[n];
}