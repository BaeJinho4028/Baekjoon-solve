#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long chk[1005];
long long sum, ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		sum += x % m;
		chk[sum % m]++;
	}

	ans += chk[0];
	for (int i = 0; i <= m; i++) {
		ans += chk[i] * (chk[i] - 1) / 2; // 나머지-나머지 =0 이면 되기에 나머지같은것들중 2개 고르기 nC2
	}

	cout << ans;
}