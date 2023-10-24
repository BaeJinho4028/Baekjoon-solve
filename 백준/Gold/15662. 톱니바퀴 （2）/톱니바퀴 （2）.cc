#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

deque<int> dq[1005];
bool vis[1005];
int t, k;

void turn(int i, int d) {
	if(vis[i]) return;
	vis[i] = true;

	if (i > 1 && dq[i - 1][2] != dq[i][6]) { // 왼쪽
		turn(i - 1, -d);
	}
	if (i < t && dq[i][2] != dq[i+1][6]) { // 오른쪽
		turn(i + 1, -d);
	}

	if (d == 1) { // 시계
		dq[i].push_front(dq[i].back());
		dq[i].pop_back();
	}
	if (d == -1) { //반시계
		dq[i].push_back(dq[i].front());
		dq[i].pop_front();
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 1; i <= t; i++) {
		for (int j = 0; j < 8; j++) {
			char c;
			cin >> c;
			dq[i].push_back(c - '0');
		}
	}

	cin >> k;
	while (k--) {
		int d, i;
		cin >> d >> i;
		turn(d, i);
		memset(vis, false, sizeof(vis));
	}

	int cnt = 0;
	for (int i = 1; i <= t; i++) {
		if (dq[i].front() == 1) cnt++;
	}
	cout << cnt;
}