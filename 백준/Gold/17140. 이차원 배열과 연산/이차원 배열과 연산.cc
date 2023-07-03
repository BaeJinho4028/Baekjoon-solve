#include <bits/stdc++.h>
using namespace std;

int r, c, k;
int board[105][105];
int chk[105];
int row = 3, col = 3;
int t;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second != b.second)
		return a.second < b.second;

	return a.first < b.first;
}

void R() {
	for (int i = 1; i <= row; i++) {
		memset(chk, 0, sizeof(chk));

		for (int j = 1; j <= col; j++)
			if (board[i][j] != 0)
				chk[board[i][j]]++; 

		vector<pair<int, int>> tmp;
		for (int j = 1; j <= 100; j++)
		{
			if (!chk[j]) continue;

			tmp.push_back({ j, chk[j] });
		}

		sort(tmp.begin(), tmp.end(), cmp);

		col = max(col, (int)tmp.size() * 2);

		for (int j = 1; j <= 100; j++)
			board[i][j] = 0;

		for (int j = 0; j < tmp.size(); j++){
			board[i][j * 2 + 1] = tmp[j].first;
			board[i][(j + 1) * 2] = tmp[j].second;
		}
	}
}

void C() {
	for (int j = 1; j <= col; j++)
	{
		memset(chk, 0, sizeof(chk)); 

		for (int i = 1; i <= row; i++)
			if (board[i][j] != 0) 
				chk[board[i][j]]++;

		vector<pair<int, int>> tmp;
		for (int i = 1; i <= 100; i++)
		{
			if (!chk[i]) continue;

			tmp.push_back({ i, chk[i] });
		}

		sort(tmp.begin(), tmp.end(), cmp);

		row = max(row, (int)tmp.size() * 2);

		for (int i = 1; i <= 100; i++)
			board[i][j] = 0;

		for (int i = 0; i < tmp.size(); i++) {
			board[i * 2 + 1][j] = tmp[i].first;
			board[(i + 1) * 2][j] = tmp[i].second;
		}
	}
}

int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> board[i][j];
		}
	}

	while (t <= 100) {
		if (board[r][c] == k) {
			cout << t;
			return 0;
		}

		t++;

		if (row >= col) R();
		else C();
	}

	cout << -1;
}