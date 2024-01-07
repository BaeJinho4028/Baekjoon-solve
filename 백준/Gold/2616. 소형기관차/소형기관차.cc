#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[50005];
int d[4][50005];

int f(int cur, int t) {
	if (cur == 3 || t > n)
		return 0;

	int& ret = d[cur][t];
	if (~ret) return ret;
	ret = 0;

	// 넘어가거나, 연속된 k칸을 고르거나
	ret = max(f(cur, t + 1), f(cur + 1, t + k) + (a[t] - a[t - k]));

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	cin >> k;

	memset(d, -1, sizeof(d));
	cout << f(0, k);
	
	return 0;
}