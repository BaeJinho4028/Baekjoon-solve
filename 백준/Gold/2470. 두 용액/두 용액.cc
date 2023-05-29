#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	int st = 0, en = n - 1;
	int mn = 0x7f7f7f7f, a, b;
	while (st < en) {
		int sum = arr[st] + arr[en];

		if (mn > abs(sum)) {
			mn = abs(sum);
			a = arr[st];
			b = arr[en];

			if (sum == 0)
				break;
		}

		if (sum < 0)
			st++;
		else
			en--;

	}

	cout << a << ' ' << b;
}