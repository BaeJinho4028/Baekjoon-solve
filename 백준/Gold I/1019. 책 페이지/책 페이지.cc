#include <bits/stdc++.h>
using namespace std;

int cnt[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int add = 0;
	for (int i = 1; n != 0; i *= 10) {
		int cur = n % 10;
		n /= 10;

		cnt[0] -= i;
		for (int j = 0; j < cur; j++) cnt[j] += (n + 1) * i;
		cnt[cur] += n * i + 1 + add;
		for (int j = cur + 1; j <= 9; j++) cnt[j] += n * i;

		add += cur * i;
	}

	for (int i = 0; i <= 9; i++) {
		cout << cnt[i] << ' ';
	}
}