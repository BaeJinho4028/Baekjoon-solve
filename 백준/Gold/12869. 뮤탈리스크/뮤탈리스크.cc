#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003

int n;
int d[65][65][65];
int hp[3];

int solve(int x, int y, int z) {
	if (x < 0) return solve(0, y, z);
	if (y < 0) return solve(x, 0, z);
	if (z < 0) return solve(x, y, 0);

	if (x == 0 && y == 0 && z == 0) return 0;

	if (d[x][y][z] != -1) return d[x][y][z];

	d[x][y][z] = '????';

	d[x][y][z] = min(d[x][y][z], solve(x - 9, y - 3, z - 1) + 1);
	d[x][y][z] = min(d[x][y][z], solve(x - 9, y - 1, z - 3) + 1);
	d[x][y][z] = min(d[x][y][z], solve(x - 3, y - 9, z - 1) + 1);
	d[x][y][z] = min(d[x][y][z], solve(x - 3, y - 1, z - 9) + 1);
	d[x][y][z] = min(d[x][y][z], solve(x - 1, y - 3, z - 9) + 1);
	d[x][y][z] = min(d[x][y][z], solve(x - 1, y - 9, z - 3) + 1);

	return d[x][y][z];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> hp[i];
	}

	memset(d, -1, sizeof(d));
	
	cout << solve(hp[0], hp[1], hp[2]);
}