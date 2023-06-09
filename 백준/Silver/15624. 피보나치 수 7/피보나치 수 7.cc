#include <bits/stdc++.h>
using namespace std;

int d[1000005];

int main() { //수신영역 최소거리가 되어야 전체값도 최솟값됨
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	d[0] = 0;
	d[1] = 1;

	for (int i = 2; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2]) % 1000000007;
	}

	cout << d[n];
}