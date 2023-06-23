#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[105][105];
bool vis[105][105];
int dx[4] = { 0,1,0,-1 }; //우 하 좌 상
int dy[4] = { 1,0,-1,0 };


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, l;
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		board[a-1][b-1] = 1;
	}

	cin >> l;
	vector<pair<int, char>> v;
	for (int i = 0; i < l; i++) {
		int a;
		char c;
		cin >> a >> c;
		v.push_back({ a,c });
	}

	queue<pair<int, int>> q;
	int cnt = 0;
	int x = 0, y = 0, dir = 0, idx = 0;
	q.push({ x, y });
	while (1) {
		cnt++;
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny]) {
			cout << cnt;
			return 0;
		}

		q.push({ nx, ny });
		vis[nx][ny] = true;
		if (board[nx][ny] == 1) { //사과먹음
			board[nx][ny] = 0;
		}
		else {
			vis[q.front().X][q.front().Y] = false;
			q.pop();
		}

		x = nx;
		y = ny;

		if (idx < v.size()) {
			if (cnt == v[idx].X) {
				if (v[idx].Y == 'D')
					dir = (dir + 1) % 4;
				else
					dir = (dir + 3) % 4;
				idx++;
			}
		}
	}
	

}