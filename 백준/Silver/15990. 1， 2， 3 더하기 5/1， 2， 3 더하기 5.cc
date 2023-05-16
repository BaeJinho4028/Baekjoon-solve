#include <bits/stdc++.h>
using namespace std;

int d[100005][4]; // 1 1  2 1  3 3  4 3  5 4  6 6  7 9

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	d[1][1] = 1;
	d[2][2] = 1;
	d[3][1] = d[3][2] = d[3][3] = 1;

	for (int i = 4; i <= 100000; i++){
		d[i][1] = (d[i - 1][2] + d[i - 1][3]) % 1000000009;
		d[i][2] = (d[i - 2][1] + d[i - 2][3]) % 1000000009;
		d[i][3] = (d[i - 3][1] + d[i - 3][2]) % 1000000009;
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		cout << ((long long) d[n][1]+d[n][2]+d[n][3]) % 1000000009 << '\n';
	}
}