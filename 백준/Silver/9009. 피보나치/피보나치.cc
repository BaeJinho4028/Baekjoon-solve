#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
#define ll long long
int dx[8] = { 1,0,-1,0, 1, 1, -1, -1 };
int dy[8] = { 0,1,0,-1, 1, -1, 1, -1 };
int n, m;
int mx, mn = '????';
int ans, cnt;

int d[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	d[1] = 1;

	for (int i = 2; i <= 45; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}

	while (t--) {
		int n;
		cin >> n;

		vector<int> v;

		for (int i = 45; i >= 1; i--) {
			if (n - d[i] >= 0) {
				v.push_back(d[i]);
				n -= d[i];
			}
		}

		sort(v.begin(), v.end());
		for (int x : v)
			cout << x << ' ';
		cout << '\n';
	}
}