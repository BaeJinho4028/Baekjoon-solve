#include <bits/stdc++.h>
using namespace std;

bool d[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	d[2] = d[4] = true;

	for (int i = 5; i <= n; i++) {
		if (d[i - 1] && d[i - 3] && d[i - 4]) d[i] = false;
		else d[i] = true;
	}

	if (d[n]) cout << "SK";
	else cout << "CY";
}