#include <bits/stdc++.h>
using namespace std;

bool chk[10]; // 고장난버튼

bool solve(int x) {
	string s = to_string(x);
	for (int i = 0; i < s.size(); i++) {
		if (chk[s[i] - '0'])
			return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//3가지 그자리에서 체크 높은번호 낮은번호
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		chk[x] = 1;
	}

	string s = to_string(n);

	int mn = abs(n - 100); //100에서 +-
	for (int i = 0; i <= 1000000; i++) {
		if (solve(i)) {
			int tmp = abs(n - i) + to_string(i).size();
			mn = min(mn, tmp);
		}
	}

	cout << mn;
}