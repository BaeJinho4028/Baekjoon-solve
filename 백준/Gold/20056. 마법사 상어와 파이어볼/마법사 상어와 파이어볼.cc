#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define ll long long
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

struct FB {
	int r, c, m, s, d;
};

int n, m, k;
vector<FB> board[55][55];
vector<FB> fb;

void move() { //1
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			board[i][j].clear();

	for (int i = 0; i < fb.size(); i++) {
		int nm = fb[i].m;
		int ns = fb[i].s;
		int dir = fb[i].d;

		int ts = ns % n;
		int nr = fb[i].r + dx[dir] * ts;
		int nc = fb[i].c + dy[dir] * ts;

		if (nr > n) nr -= n;
		if (nr < 1) nr += n;
		if (nc > n) nc -= n;
		if (nc < 1) nc += n;

		board[nr][nc].push_back({ nr, nc, nm, ns, dir });
		fb[i].r = nr;
		fb[i].c = nc;
	}
}

void sum(){
	vector<FB> tmp;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j].size() == 0) continue;
			if (board[i][j].size() == 1) {
				tmp.push_back(board[i][j][0]);
				continue;
			}

			int m_sum = 0;
			int s_sum = 0;
			int cnt = board[i][j].size();
			
			bool Even = true;
			bool Odd = true;

			for (int k = 0; k < (int)board[i][j].size(); k++) {
				m_sum += board[i][j][k].m;
				s_sum += board[i][j][k].s;
				if (board[i][j][k].d % 2 == 0) Odd = false;
				else Even = false;
			}




			int nm = m_sum / 5;
			int ns = s_sum / cnt;

			if (nm == 0) continue;

			if (Even == true || Odd == true) {
				for (int dir = 0; dir <= 6; dir += 2) {
					tmp.push_back({ i, j, nm, ns, dir });
				}
			}
			else {
				for (int dir = 1; dir <= 7; dir += 2) {
					tmp.push_back({ i, j, nm, ns, dir });
				}
			}
		}
	}
	fb = tmp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fb.push_back({ r, c, m, s, d });
		board[r][c].push_back({ r, c, m, s, d });
	}

	while (k--) {
		move();
		sum();
	}

	int ans = 0;
	for (int i = 0; i < (int)fb.size(); i++)
		ans += fb[i].m;

	cout << ans;
}