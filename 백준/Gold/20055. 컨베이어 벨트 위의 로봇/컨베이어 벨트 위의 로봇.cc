#include <bits/stdc++.h>
using namespace std;

deque<pair<int, bool>> dq; //내구도, 로봇이 올라가 있는지?
int n, k;

void rotate() {
	dq.push_front(dq.back());
	dq.pop_back();

	dq[n - 1].second = false; //로봇내려감
	return;
}

void move() {
	for (int i = n - 2; i >= 0; i--) {
		if (dq[i].second) { //일단 로봇이 잇어야함
			if (!dq[i + 1].second && dq[i + 1].first >= 1) { // 앞에 로봇 없어야하며 내구도 1이상
				dq[i].second = false;
				dq[i + 1].second = true;
				dq[i + 1].first--;
			}
		}
	}

	dq[n - 1].second = false; //로봇내려감
	return;
}

void up() { 
	if (dq[0].first > 0 && !dq[0].second) { // 내구도 0이아니어야 하며 로봇이 없어야함
		dq[0].second = true;
		dq[0].first--;
	}

	return;
}

int chk() {
	int cnt = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (dq[i].first <= 0) cnt++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < 2 * n; i++) {
		int x;
		cin >> x;
		dq.push_back({ x, false });
	}


	int ans = 1;
	while (1) {
		rotate();
		move();
		up();

		if (k <= chk()) break;
		ans++;
	}

	cout << ans;
}