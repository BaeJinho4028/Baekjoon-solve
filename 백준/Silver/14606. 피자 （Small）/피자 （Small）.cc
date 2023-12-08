#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define ll long long

int d[15];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	d[1] = 0;
	d[2] = 1;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + (i - 1);
	}
	cout << d[n];
}