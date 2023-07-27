#include <bits/stdc++.h>
using namespace std;

int ans;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	int tmp = b / a;

	/*
	lcm = x * y * gcd
	x* gcd 와 y* gdc를 구하기?

	tmp = lcm/gcd
	x와 y는 tmp의 약수이자 서로소
	*/

	for (int i = 1; i * i <= tmp; i++) {
		if (tmp % i == 0) {
			int x = i, y = tmp / i;

			if (gcd(x, y) == 1) {
				ans = x; //끝까지 탐색함으로써 두 자연수의 합이 최소
			}
		}
	}

	cout << a * ans << ' ' << a * (tmp / ans);
}