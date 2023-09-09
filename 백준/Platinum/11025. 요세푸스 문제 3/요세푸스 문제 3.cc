#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;

	cin >> n >> k;

	int ans = 0;
	for (int i = 2; i <= n; i++) {
		ans = (ans + k) % i;
	}

	cout << ans + 1;
}