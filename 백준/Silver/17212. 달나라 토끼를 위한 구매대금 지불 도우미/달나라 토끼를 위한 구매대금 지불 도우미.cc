#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define ll long long

int d[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	d[1] = d[2] = d[5] = d[7] = 1;
	d[3] = d[4] = d[6] = 2;

	for (int i = 8; i <= n; i++) {
		d[i] = min({ d[i - 1], d[i - 2], d[i - 5], d[i - 7] }) + 1;
	}
	cout << d[n];
}