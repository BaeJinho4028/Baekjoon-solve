#include <bits/stdc++.h>
using namespace std;

int n, m;
char board[10][10];
int ans = -1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			for (int dx = -n; dx < n; dx++) {
				for (int dy = -m; dy < m; dy++) {
					if (!dx && !dy) continue;
					int nx = i;
					int ny = j;
					int sum = 0;

					while (nx >= 0 && nx < n && ny >= 0 && ny < m) {
						sum *= 10;
						sum += board[nx][ny] - '0';
						nx += dx;
						ny += dy;

						int tmp = (int)sqrt(sum);
						if (sum == tmp * tmp) ans = max(ans, sum);
					}
				}
			}
		}
	}
	cout << ans;
}