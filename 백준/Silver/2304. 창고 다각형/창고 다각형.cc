#include <bits/stdc++.h>
using namespace std;

int mx, idx, ans;
int a[1005];

int main() { //스택으로 도전하다 머리깨질거같아 실패.. 왼쪽 오른쪽 최대 더해주기방법
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int l, h;
		cin >> l >> h;
		a[l] = h;
		if (mx < h) {
			idx = l;
			mx = h;
		}
	}

	int tmp = 0; //왼쪽 최고높이
	for (int i = 0; i < idx; i++) {
		tmp = max(tmp, a[i]);
		ans += tmp;
	}

	tmp = 0; //오른쪽 최고높이
	for (int i = 1000; i > idx; i--) {
		tmp = max(tmp, a[i]);
		ans += tmp;
	}
	ans += mx;

	cout << ans;
}