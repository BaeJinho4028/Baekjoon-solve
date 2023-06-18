#include <bits/stdc++.h>
using namespace std;

int a[35], b[35];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int d, k;
	cin >> d >> k;

	a[1] = 1; //날짜별 a와 b : 값은 앞의 계수이다.
	b[2] = 1;

	for (int i = 3; i <= 30; i++) {
		a[i] = a[i - 1] + a[i - 2];
		b[i] = b[i - 1] + b[i - 2];
	}

	for (int i = 1;; i++) {
		for (int j = 1;; j++) {
			if (a[d] * i + b[d] * j == k) {
				cout << i << '\n' << j;
				return 0;
			}

			if (a[d] * i + b[d] * j > k) break;
		}
	}
}
/*
1 : a
2 : b
3 : a + b
4 : a + 2b
5 : 2a + 3b
6 : 3a + 5b
*/