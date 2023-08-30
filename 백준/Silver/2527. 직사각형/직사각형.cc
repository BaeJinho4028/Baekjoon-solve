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
ll mx, mn = '????';

int a[4];
int b[4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++) {

		for (int i = 0; i < 4; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < 4; i++) {
			cin >> b[i];
		}

		int xl = max(a[0], b[0]);
		int yl = max(a[1], b[1]);
		int xr = min(a[2], b[2]);
		int yr = min(a[3], b[3]);

		int x = xr - xl;
		int y = yr - yl;

		if (x > 0 && y > 0) cout << "a\n";
		else if (x == 0 && y == 0) cout << "c\n";
		else if (x < 0 || y < 0) cout << "d\n";
		else cout << "b\n";
	}
}