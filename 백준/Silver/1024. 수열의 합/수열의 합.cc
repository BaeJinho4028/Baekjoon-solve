#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	cin >> n >> l;

	int st = -1, idx = 0; //st: 수열 시작, idx 수열 길이
	for (int i = l; i <= 100; i++) {
		int t = i * (i - 1) / 2; //1등차수열 합
		//Lx + t  ->  x = (n-t)/L

		if ((n - t) % i == 0 && (n - t) / i >= 0) { // (n-t)가 L로 나눠지는지 = x가 정수인지
			st = (n - t) / i;
			idx = i;
			break;
		}
	}

	if(st == -1)cout << st << '\n';
	else
		for (int i = 0; i < idx; i++)
			cout << st + i << ' ';
}