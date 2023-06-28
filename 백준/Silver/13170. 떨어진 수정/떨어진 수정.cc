#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, p, w;
	cin >> n >> k >> p >> w;

	for (int i = 1;; i++) {
		if (p <= w * i) {
			cout << i;
			return 0;
		}
	}
}