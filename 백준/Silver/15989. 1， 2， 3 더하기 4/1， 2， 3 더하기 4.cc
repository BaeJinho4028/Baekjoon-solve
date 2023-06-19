#include <bits/stdc++.h>
using namespace std;

long long d[10005][4]; //[n][맨뒤 숫자]  ,, 무조건 합은 오름차순

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	d[1][1] = 1;
	d[2][1] = d[2][2] = 1;
	d[3][1] = d[3][2] = d[3][3] = 1;

	for (int i = 4; i <= 10000; i++) {
		d[i][1] = d[i - 1][1];
		d[i][2] = d[i - 2][1] + d[i - 2][2]; //맨뒤가 2이므로 i-2
		d[i][3] = d[i - 3][1] + d[i - 3][2] + d[i - 3][3];
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		cout << d[n][1] + d[n][2] + d[n][3] << '\n';
	}
}