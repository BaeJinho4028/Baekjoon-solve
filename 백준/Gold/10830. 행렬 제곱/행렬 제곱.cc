#include <bits/stdc++.h>
using namespace std;

long long n, b;
long long a[5][5], tmp[5][5], ans[5][5];

void solve(long long x[5][5], long long y[5][5]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = 0;
			for (int k = 0; k < n; k++)
				tmp[i][j] += (x[i][k] * y[k][j]);
			tmp[i][j] %= 1000; //모듈러 연산 (a mod C x b mod C) mod C = (a x b) % C
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			x[i][j] = tmp[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
		ans[i][i] = 1;// 단위행렬
	}

	while (b) { //제곱 : 지수법칙 (전에품)
		if (b % 2 == 1)
			solve(ans, a);

		solve(a, a);
		b /= 2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}