#include <bits/stdc++.h>
using namespace std;

int mx, idx, ans;
int a[1005];

int main() { //스택으로 도전하다 머리깨질거같아 실패.. 왼쪽 오른쪽 최대 더해주기방법
	ios::sync_with_stdio(0);
	cin.tie(0);

	string ans;
	int n;
	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	while (n) {
		if (n % -2 == 0) {
			ans += "0";
			n /= -2;
		}
		else { //홀수일 경우 미리 1을 빼고 나눠준뒤 결과값에 1 더함
			ans += "1";
			n = (n - 1) / -2;
		}
	}

	reverse(ans.begin(), ans.end());
	cout << ans;
}