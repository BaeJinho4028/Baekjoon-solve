#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

char board[12][6], tmp[12];
bool vis[12][6];
int ans, cnt;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool flag;
vector<pair<int, int>> v;

void dfs(int x, int y) {
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
		if (vis[nx][ny] || board[nx][ny] != board[x][y]) continue;

		cnt++;
		vis[nx][ny] = true;
		v.push_back({ nx, ny });
		dfs(nx, ny);
	}
}

void boom() { //터짐 .으로 변경
	for (auto a : v) {
		board[a.X][a.Y] = '.';
	}
	flag = true; //터짐
}

bool chk() {
	flag = false;

	memset(vis, false, sizeof(vis));

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (board[i][j] != '.' && !vis[i][j]) {
				cnt = 1;
				v.clear();
				v.push_back({ i, j });
				vis[i][j] = true;
				dfs(i, j);

				if (cnt >= 4) boom();
			}

		}
	}

	return flag;
}

void down() {
	queue<char> q;
	for (int j = 0; j < 6; j++) {
		int t = 11;
		for (int i = 11; i >= 0; i--) {
			if (board[i][j] != '.') q.push(board[i][j]);
			tmp[i] = '.';
		}

		while (!q.empty()) {
			tmp[t--] = q.front();
			q.pop();
		}

		for (int i = 11; i >= 0; i--) {
			board[i][j] = tmp[i];
		}
	}
}

int main() { //벨만포드 맛보기 : 음수 사이클
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> board[i][j];
		}
	}

	while (1) {
		if (chk()) ans++;
		else break;

		down();	
	}

	cout << ans;
}