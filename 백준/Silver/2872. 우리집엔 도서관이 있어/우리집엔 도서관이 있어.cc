#include <bits/stdc++.h>
using namespace std;

int a[300005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int cnt = n;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == cnt)
			cnt--;
	}
	cout << cnt;
}