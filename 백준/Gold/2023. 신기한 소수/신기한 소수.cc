#include <bits/stdc++.h>
using namespace std;

int n;

bool chk(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

void solve(int num, int cur) {// 숫자와 길이
	if (cur == n) {
		cout << num << '\n';
		return;
	}

	for (int i = 1; i <= 9; i += 2) {
		if (chk(num * 10 + i))
			solve(num * 10 + i, cur + 1);
	}
}

int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	solve(2, 1);
	solve(3, 1);
	solve(5, 1);
	solve(7, 1);
}
