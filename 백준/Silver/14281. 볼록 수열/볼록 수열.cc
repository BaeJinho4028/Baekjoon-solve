#include <bits/stdc++.h>
using namespace std;

int a[55];

int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	if (n <= 2) {
		cout << 0;
		return 0;
	}

	long long ans = 0;
	while (1) {
		bool flag = false;
		for (int i = 1; i < n - 1; i++) {
			if (a[i - 1] + a[i + 1] < a[i] * 2) {
				long long tmp = (a[i - 1] + a[i + 1]) / 2;
				ans += a[i] - tmp;
				a[i] = tmp;
				flag = true;
			}
		}
		if (!flag) break;
	}

	cout << ans;
}