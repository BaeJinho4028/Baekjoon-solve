#include <bits/stdc++.h>
using namespace std;

string a, b;
int n;

void turn(string& s, int idx) {
	for (int i = idx - 1; i <= idx + 1; i++) {
		if (i < 0 || i >= n) continue;

		if (s[i] == '0') s[i] = '1';
		else s[i] = '0';
	}
}

int chk(string st, string en, bool flag) {
	int cnt = 0;

	if (flag) { //0번째 전구 바꾸는 경우
		turn(st, 0);
		cnt++;
	}

	for (int i = 1; i < n; i++) {
		if (st[i - 1] != en[i - 1]) {
			turn(st, i);
			cnt++;
		}
	}

	if (st != en) cnt = '????';

	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> a >> b;

	int ans = min(chk(a, b, false), chk(a, b, true));

	if (ans == '????') cout << -1;
	else cout << ans;
}