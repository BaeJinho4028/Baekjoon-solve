#include <bits/stdc++.h>
using namespace std;

int a[9], b[9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x =0 , y =0;
	bool flag = false;

	for (int i = 0; i < 9; i++)
		cin >> a[i];
	for (int i = 0; i < 9; i++)
		cin >> b[i];

	for (int i = 0; i < 9; i++) {
		x += a[i];
		if (x > y) flag = true;
		y += b[i];
	}

	if (flag) cout << "Yes";
	else cout << "No";
}