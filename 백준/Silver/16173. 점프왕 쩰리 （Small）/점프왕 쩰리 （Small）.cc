#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[4][4];
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
bool vis[4][4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({ 0,0 });
    vis[0][0] = true;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 2; dir++) {
            int nx = cur.X + dx[dir] * board[cur.X][cur.Y];
            int ny = cur.Y + dy[dir] * board[cur.X][cur.Y];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = true;
            q.push({ nx, ny });
        }
    }

    if (vis[n-1][n-1]) cout << "HaruHaru";
    else cout << "Hing";
}