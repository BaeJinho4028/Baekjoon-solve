#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);
	
	for (int i = n; i >= 0; i--) {
		int cnt = 0;
		for (int j = 0; j < n; j++)
			if (a[j] >= i)
				cnt++;

		if (cnt >= i) {
			cout << i;
			return 0;
		}
	}
}
