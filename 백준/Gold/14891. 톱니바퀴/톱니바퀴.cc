#include <bits/stdc++.h>
using namespace std;

vector<deque<int>> v(5);
bool chk[5];
int rotation[5];

void rset(int a, int b) {
	rotation[a] = b;
	chk[a] = true;

	if (a > 1 && !chk[a - 1]) { // 왼쪽 세팅
		if (b == 0) //회전 안할경우
			rset(a - 1, 0);

		else if (v[a][6] == v[a - 1][2]) // 맞닿은극 같음
			rset(a - 1, 0);

		else //맞닿은극 다름
			rset(a - 1, -b);
	}

	if (a <= 3 && !chk[a + 1]) { //오른쪽 세팅
		if (b == 0) //회전 안할경우
			rset(a + 1, 0);

		else if (v[a][2] == v[a + 1][6]) // 맞닿은극 같음
			rset(a + 1, 0);

		else //맞닿은극 다름
			rset(a + 1, -b);
	}
}

void rotate() {
	for (int i = 1; i <= 4; i++) {
		if (rotation[i] == 0)
			continue;

		if (rotation[i] == 1) {
			int tmp = v[i].back();
			v[i].push_front(tmp);
			v[i].pop_back();
		}

		else {
			int tmp = v[i].front();
			v[i].push_back(tmp);
			v[i].pop_front();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	for (int i = 1; i <= 4; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++) {
			v[i].push_back(s[j] - '0');
		}
	}

	int k;
	cin >> k;

	while (k--) {
		int a, b;
		cin >> a >> b;
		memset(chk, false, sizeof(chk));
		rset(a, b);
		rotate();
	}

	int ans = 0;

	for (int i = 1; i <= 4; i++) {
		if (v[i][0] == 1) {
			ans += pow(2, i - 1);
		}
	}

	cout << ans;
}