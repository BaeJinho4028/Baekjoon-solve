#include <bits/stdc++.h>
using namespace std;

int a[3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a[0] >> a[1] >> a[2];

	sort(a, a + 3);

	cout << a[1];
}