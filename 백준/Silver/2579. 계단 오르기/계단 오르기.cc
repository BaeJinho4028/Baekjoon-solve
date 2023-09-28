#include <bits/stdc++.h>
using namespace std;

int d[303]; //밟지않을 계단의 합의 최솟값, i번째 계단은 반드시 밟지않을 계단으로 선택해야함
int s[303];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int t = 0;
	
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		t += s[i];
	}

	if (n <= 2) {
		cout << t;
		return 0;
	}

	d[1] = s[1]; d[2] = s[2]; d[3] = s[3];

	for (int i = 4; i <= n - 1; i++) 
		d[i] = min(d[i - 2], d[i - 3]) + s[i];

	cout << t - min(d[n - 1], d[n - 2]);
}