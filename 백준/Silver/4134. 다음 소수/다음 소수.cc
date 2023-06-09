#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		long long n;
		cin >> n;

		if (n <= 2) {
			cout << '2' << '\n';
			continue;
		}

		while (1) {
			bool flag = true;
			for (long long i = 2; i * i <= n; i++) {
				if (n % i == 0) {
					flag = false;
					break;
				}
			}
			if (flag) break;
			n++;
		}

		cout << n << '\n';
	}
}