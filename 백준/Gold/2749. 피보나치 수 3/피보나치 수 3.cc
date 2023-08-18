#include <bits/stdc++.h>
using namespace std;

long long d[1500005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;

	d[1] = 1;
	for (int i = 2; i <= 1500000; i++)
		d[i] = (d[i - 1] + d[i - 2]) % 1000000;

	cout << d[n % 1500000] << '\n';
}