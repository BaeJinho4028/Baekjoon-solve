#include <bits/stdc++.h>
using namespace std;

int n, mx;
int a[25], b[25]; //체력 점수

void solve(int hp, int cnt, int cur) {
	if (hp <= 0 || cur > n) return;
	mx = max(mx, cnt);

	solve(hp - a[cur], cnt + b[cur], cur + 1);
	solve(hp , cnt, cur + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	solve(100, 0, 0);

	cout << mx;
}