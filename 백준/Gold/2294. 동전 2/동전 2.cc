#include <bits/stdc++.h>
using namespace std;

int a[10005], d[10005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	
	for (int i = 1; i <= k; i++)
		d[i] = 0x7f7f7f7f;

	for (int i = 1; i <= n; i++)
		for (int j = a[i]; j <= k; j++)
			d[j] = min(d[j], d[j - a[i]] + 1);
	

	if (d[k] == 0x7f7f7f7f) cout << -1;
	else cout << d[k];
}