#include <bits/stdc++.h>
using namespace std;

/*
0세대 : 0
1세대 : 0 1
2세대 : 0 1 2 1
3세대 : 0 1 2 1 2 3 2 1

>> i세대는 i-1세대 + (i-1를 90도로 회전시킨것(+1)을 반대로 나열한것)


입력받기 > 0세대 선분 하나 그리기 > 방향 저장 
> g세대까지 드래곤커브 >(이전까지 반복후) 정사각형 카운팅
*/

int dx[4] = { 0,-1,0,1 }; //0오른쪽 1위쪽 2왼쪽 3아래
int dy[4] = { 1,0,-1,0 };
int n;
int board[105][105];
int x, y, d, g;
vector<int> dir;

void dc(){ //드래곤 커브
	int s = dir.size();
	for (int i = s - 1; i >= 0; i--) {
		int nd = (dir[i] + 1) % 4;
		x += dx[nd];
		y += dy[nd];
		board[x][y] = 1;

		dir.push_back(nd);
	}
}

int chk() { //정사각형 체크
	int cnt = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (board[i][j] == 1 && board[i][j+1] == 1 &&
				board[i+1][j] == 1 && board[i+1][j+1] == 1)
				cnt++;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> y >> x >> d >> g;

		dir.clear();

		board[x][y] = 1;
		x += dx[d];
		y += dy[d];
		board[x][y] = 1;

		dir.push_back(d);

		for (int j = 0; j < g; j++)
			dc();
	}

	cout << chk();
}