#include <bits/stdc++.h>
using namespace std;

int d[10005];
int a[10005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	d[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = a[i]; j <= k; j++)
			d[j] += d[j - a[i]];

	cout << d[k];
}