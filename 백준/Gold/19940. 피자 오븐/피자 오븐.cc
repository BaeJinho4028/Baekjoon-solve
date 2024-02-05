#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int a[5] = { 0, };
		int n;
		cin >> n;

		a[0] += n / 60;
		n %= 60;

		if (n <= 35) {
			if (n % 10 > 5) {
				a[1] += n / 10 + 1;
				a[4] += 10 - n % 10;
			}
			else {
				a[1] += n / 10;
				a[3] += n % 10;
			}
		}
		else {
			a[0]++;

			if (n % 10 >= 5) {
				a[2] += 6 - (n / 10 + 1);
				a[4] += 10 - n % 10;
			}
			else {
				a[2] += 6 - n / 10;
				a[3] += n%10;
			}
		}

		for (int i = 0; i < 5; i++)
			cout << a[i] << ' ';
		cout << '\n';
	}
}