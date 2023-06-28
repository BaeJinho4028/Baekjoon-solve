#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) { //while문 시간 초과  ->  일차방정식의 교점 풀이
		int p, q, a, b, c, d;
		cin >> p >> q >> a >> b >> c >> d;

		int coin = (q / c) * d; //코인 환전

		p += (coin / b) * a; //p최대화
		coin %= b; //coin 최소화

		//y = p - ax = coin + bx 의 교점

		int x = (p - coin) / (a + b); //실수에서 정수가 되어 답이 x일수도 x+1일수도

		int ans = max(min(coin + b * x, p - a * x),
			min(coin + b * (x + 1), p - a * (x + 1)));

		cout << ans << "\n";
	}
}