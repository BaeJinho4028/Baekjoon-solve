#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
int dx[8] = { 1,0,-1,0 };
int dy[8] = { 0,1,0,-1 };
int n, m;
int mx, mn = '????';

int a[100005];
int sum[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = a[i] + sum[i - 1];
	}

	//// 벌 벌 꿀 : 왼쪽맨끝 벌, 오른맨끝 꿀, 벌 하나는 움직이며
	for (int i = 2; i < n; i++) { 
		int tmp = (sum[n] - sum[1] - a[i]) + (sum[n] - sum[i]);
		mx = max(mx, tmp);
	}

	//// 벌 꿀 벌 : 양쪽끝 벌, 꿀통 움직이기
	for (int i = 2; i < n; i++) {
		int tmp = (sum[i] - sum[1]) + (sum[n - 1] - sum[i - 1]);
		mx = max(mx, tmp);
	}

	//// 꿀 벌 벌 : 중간 벌만 움직이기
	for (int i = 2; i < n; i++) {
		int tmp = sum[i - 1] + (sum[n - 1] - a[i]);
		mx = max(mx, tmp);
	}

	cout << mx;
}