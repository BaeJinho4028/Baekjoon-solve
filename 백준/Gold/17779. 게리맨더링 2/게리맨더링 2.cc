#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int n;
int board[25][25];
int tmp[25][25];
vector<pair<int, int>> v;
int sum[6];
int mn = '????';
int cnt;

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = 5;
		}
	}

	//v : 0상 1좌 2우 3하
	cnt = 0;
	for (int i = 0; i < v[1].X; i++) {
		if (i >= v[0].X) cnt++;
		for (int j = 0; j <= v[0].Y - cnt; j++) {
			tmp[i][j] = 1;
		}
	}

	cnt = 0;
	for (int i = 0; i <= v[2].X; i++) {
		if (i > v[0].X) cnt++;
		for (int j = v[0].Y +1 + cnt; j < n; j++) {
			tmp[i][j] = 2;
		}
	}

	cnt = 0;
	for (int i = n - 1; i >= v[1].X; i--) {
		if (i < v[3].X) cnt++;
		for (int j = 0; j < v[3].Y - cnt; j++) {
			tmp[i][j] = 3;
		}
	}

	cnt = 0;
	for (int i = n - 1; i > v[2].X; i--) {
		if (i <= v[3].X) cnt++;
		for (int j = v[3].Y + cnt; j < n; j++) {
			tmp[i][j] = 4;
		}
	}
}

void cal() {
	for (int i = 0; i < 6; i++)
		sum[i] = 0;

	int s = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum[tmp[i][j]] += board[i][j];
		}
	}

	sort(sum, sum + 6);
	s = sum[5] - sum[1];
	mn = min(mn, s);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int d1 = 1; d1 <= j; d1++) {
				for (int d2 = 1; d2 <= n - j; d2++) {
					if (i + d1 >= n || j - d1 < 0) continue;
					if (i + d2 >= n || j + d2 >= n) continue;
					if (i + d1 + d2 >= n || j - d1 + d2 < 0) continue;

					v.clear();
					v.push_back({ i, j }); //상
					v.push_back({ i + d1, j - d1 }); //좌
					v.push_back({ i + d2, j + d2 }); //우
					v.push_back({ i + d1 + d2, j - d1 + d2 }); //하
					solve();
					cal();
				}
			}
		}
	}

	cout << mn;
}