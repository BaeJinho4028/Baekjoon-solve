#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll d[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 1; i <= 1000000; i++) {
		for (int j = i; j <= 1000000; j += i) {
			d[j] += i;
		}
		d[i] += d[i - 1];
	}

	while (t--) {
		int n;
		cin >> n;

		cout << d[n] << '\n';
	}
}