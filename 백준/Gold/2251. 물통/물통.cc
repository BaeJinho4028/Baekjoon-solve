#include <bits/stdc++.h>
using namespace std;

bool vis[205][205][205];

int main() { 
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c; // 물통 용량
	cin >> a >> b >> c;

	queue<tuple<int, int, int>> q;
	vector<int> v;

	q.push({ 0, 0, c }); //물
	while (!q.empty()) {
		int x, y, z; //각통에 담긴 물
		tie(x, y, z) = q.front();
		q.pop();

		if (vis[x][y][z]) continue;
		vis[x][y][z] = true;

		if (x == 0) v.push_back(z);

		if (x + y > a) q.push({ a , x + y - a, z }); // b to a
		else q.push({ x + y, 0, z });

		if (x + z > a) q.push({ a,  y, x + z - a }); // c to a
		else q.push({ x + z, y, 0 });

		if (x + y > b) q.push({ x+ y - b , b, z }); //a to b
		else q.push({ 0, x + y, z });

		if (y + z > b) q.push({ x , b, y + z - b }); // c to b
		else q.push({ x, y + z, 0 });

		if (x + z > c) q.push({ x + z - c , y, c }); // a to c
		else q.push({ 0, y, x + z });

		if (y + z > c) q.push({ x , y + z - c, c }); // b to c
		else q.push({ x, 0, y + z });
	}

	sort(v.begin(), v.end());
	for (int t : v)
		cout << t << ' ';
}
