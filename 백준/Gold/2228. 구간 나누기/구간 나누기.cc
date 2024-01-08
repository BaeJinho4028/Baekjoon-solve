#include <bits/stdc++.h>
using namespace std;

int a[105];
int d[105][55];
int n, m;

int f(int cur, int num) { //범위 개수
	if (num == 0) return 0;
	if (cur <= 0) return -'????';

	int& ret = d[cur][num];
	if (~ret) return ret;

	ret = f(cur - 1, num);
	for (int i = cur; i > 0; i--) {
		ret = max(ret, f(i - 2, num - 1) + a[cur] - a[i - 1]);
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}

	memset(d, -1, sizeof(d));
	cout << f(n, m);

	return 0;
}