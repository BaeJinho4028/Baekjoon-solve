#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

ll a[200005];
ll d[200005];
int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	ll mx = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		sum += a[i];
	}

	if (sum < m) {
		cout << -1;
		return 0;
	}
	if (mx >= m) {
		cout << "Free!";
		return 0;
	}

	int st = 1, en = n - 1; //편의를 위해 1씩 증가
	while (st <= en) {
		int mid = (st + en) / 2;

		for (int i = 1; i <= mid; i++) {
			d[i] = max(d[i - 1], a[i]);
		}
		for (int i = mid + 1; i <= n; i++) {
			d[i] = max(d[i - 1], a[i] + d[i-mid]);
		}

		if (d[n] >= m) {
			st = mid + 1;
		}
		else {
			en = mid - 1;
		}
	}

	cout << en-1;
}