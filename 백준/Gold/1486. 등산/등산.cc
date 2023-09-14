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
// + public   - private   # protected     _ static

int dist[1005][1005];

int board[105][105];
int arr[1005];
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, t, d;
	cin >> n >> m >> t >> d;

	memset(dist, '????', sizeof(dist));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			
			v.push_back(i * m + j);

			if ('a' <= c && c <= 'z') board[i][j] = c - 'a' + 26;
			else board[i][j] = c - 'A';

			arr[i * m + j] = board[i][j];
		}
	}

	for (int i = 0; i < 1000; i++) {
		dist[i][i] = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];

				if (nx<0 || nx >= n || ny <0 || ny >=m) continue;
				if (abs(board[i][j] - board[nx][ny]) > t) continue;
				int a = i * m + j;
				int b = nx * m + ny;

				if (board[i][j] >= board[nx][ny]) dist[a][b] = 1;
				else dist[a][b] = (board[i][j] - board[nx][ny]) * (board[i][j] - board[nx][ny]);
			}
		}
	}

	for (auto k : v) {
		for (auto i : v) {
			for (auto j : v) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	int ans = 0;
	for (auto k : v) {
		if (dist[0][k] + dist[k][0] <= d) ans = max(ans, arr[k]);
	}

	cout << ans;
}