#include <bits/stdc++.h>
using namespace std;

int s[105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int w, h, n;
	cin >> w >> h >> n;

	int a, b;
	for (int i = 0; i <= n; i++) {
		cin >> a >> b;
		//왼쪽위끝점부터 시계 방향 거리
		if (a == 1) //북쪽
			s[i] = b;
		if (a == 2) //남쪽
			s[i] = h + 2 * w - b;
		if (a == 3) //서쪽
			s[i] = 2 * (h + w) -b;
		if (a == 4) //동쪽
			s[i] = w + b;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int tmp = abs(s[n] - s[i]);
		if (tmp > w + h) tmp = 2 * (w + h) - tmp; //최대거리는 w+h이다. 그거보다 크면 최소거리가 있음
		ans += tmp;
	}
	cout << ans;
}