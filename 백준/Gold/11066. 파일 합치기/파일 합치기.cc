#include <bits/stdc++.h>
using namespace std;

int sum[505]; //합
int d[505][505]; //i부터 j 까지 합치는데 필요한 최소비용

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> sum[i];
			sum[i] += sum[i - 1];
		}

		for (int i = 1; i <= n; i++) { //범위
			for (int j = 1; j <= n - i; j++) { //범위시작점
				d[j][i + j] = '????';
				for (int k = j; k < i + j; k++) { //구해야하는 부분 나누는 점
					d[j][i + j] = min(d[j][i + j], d[j][k] + d[k + 1][i + j] + sum[i + j] - sum[j - 1]);
				}
			}
		}

		cout << d[1][n] << '\n';
	}
}