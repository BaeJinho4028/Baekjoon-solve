#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dist[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int s;
	cin >> s;

	queue<pair<int, int>> q; //현재 개수, 클립보드 개수
	q.push({ 1, 0 });
	dist[1][0] = 1;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		if (cur.X == s) {
			cout << dist[cur.X][cur.Y] - 1;
			break;
		}


		if (dist[cur.X][cur.X] == 0) { //복사
			q.push({ cur.X, cur.X });
			dist[cur.X][cur.X] = dist[cur.X][cur.Y] + 1;
		}

		if (cur.X + cur.Y <= s) { //붙여넣기
			if (dist[cur.X + cur.Y][cur.Y] == 0) {
				q.push({ cur.X + cur.Y, cur.Y });
				dist[cur.X + cur.Y][cur.Y] = dist[cur.X][cur.Y] + 1;
			}
		}

		if (cur.X > 0) {//삭제
			if (dist[cur.X - 1][cur.Y] == 0) {
				q.push({ cur.X - 1, cur.Y });
				dist[cur.X - 1][cur.Y] = dist[cur.X][cur.Y] + 1;
			}
		}
	}
}