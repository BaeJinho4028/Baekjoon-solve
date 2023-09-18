#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define ll long long
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1};

int n, x, y, t;
int arr[25];
int d[25][25][25];

int solve(int a, int b, int cur) {
	if (cur == t + 1)
		return 0;

	int& ret = d[a][b][cur];
	if (ret != -1)
		return ret;
	ret = 0;

	ret = min(abs(arr[cur] - a) + solve(arr[cur], b, cur + 1), abs(arr[cur] - b) + solve(a, arr[cur], cur + 1));
	
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> x >> y;

	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> arr[i];
	}

	memset(d, -1, sizeof(d));
	cout << solve(x, y, 1);
}