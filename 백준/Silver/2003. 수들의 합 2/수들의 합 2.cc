#include <bits/stdc++.h>
using namespace std;

int arr[10005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int st = 0, en = 1, ans = 0;
	long long tmp = arr[0];
	while (1) {
		if (tmp == m) ans++;
		if (tmp <= m) tmp += arr[en++];
		if (tmp > m) tmp -= arr[st++];
		if (en > n) break;
	}
	cout << ans;
}