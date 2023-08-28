#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
#define ll long long
int dx[8] = { 1,0,-1,0 };
int dy[8] = { 0,1,0,-1 };
int n, m;
ll mx, mn = '????';

int a[250005];
int sum[250005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}

	int cnt = 1;

	for (int i = m; i <= n; i++) {
		int tmp = sum[i] - sum[i - m];
		if (mx < tmp) {
			cnt = 1;
			mx = tmp;
		}
		else if (mx == tmp) {
			cnt++;
		}
	}

	if(mx == 0) cout << "SAD";
	else cout << mx << '\n' << cnt;
}