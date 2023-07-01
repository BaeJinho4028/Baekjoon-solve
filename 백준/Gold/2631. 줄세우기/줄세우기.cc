#include <bits/stdc++.h>
using namespace std;

int a[205], d[205];

int main() { //전체 - '가장 긴 증가하는 부분수열'의 크기
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		d[i] = 1;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[j] < a[i]) d[i] = max(d[i], d[j] + 1);

	cout << n - *max_element(d, d + n);
}