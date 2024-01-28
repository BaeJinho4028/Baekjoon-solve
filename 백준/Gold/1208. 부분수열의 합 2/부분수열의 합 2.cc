#include <bits/stdc++.h>
using namespace std;

int n, s;
int a[45];
map<int, int> ma;
long long cnt;

void r(int cur, int sum) {
	if (cur == n) {
		ma[sum]++;
		return;
	}

	r(cur + 1, sum + a[cur]);
	r(cur + 1, sum);
}

void l(int cur, int sum) {
	if (cur == n / 2) {
		cnt += ma[s - sum];
		return;
	}

	l(cur + 1, sum + a[cur]);
	l(cur + 1, sum);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	r(n / 2, 0);
	l(0, 0);

	if (!s) cnt--;
	cout << cnt;
}